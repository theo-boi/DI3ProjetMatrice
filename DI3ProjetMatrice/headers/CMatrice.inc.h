#ifndef CMATRICEH
#include "../headers/CMatrice.h"
#endif
#include <iostream>

/*** Constructeurs et destructeurs ***/

template<class T>
CMatrice<T>::CMatrice() {
	ppdMATelem = nullptr;
};

template<class T> template<class T2>
CMatrice<T>::CMatrice(const CMatrice<T2>& MAT2arg) throw(CException) {
	//Test a mettre dans le constructeur de conversion du template : operator ClassDifferente()
	try { (T) MAT2arg.MATgetElem(0,0); }
	catch (...) {
		CException EXCConversion;
		EXCConversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCConversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
		throw(EXCConversion);
	}

	//init
	uiMATdimLigne = MAT2arg.MATgetDimLigne();
	uiMATdimColonne = MAT2arg.MATgetDimColonne();

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MAT2arg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = MAT2arg.MATgetElem(uiBoucleForX, uiBoucleForY);
		}
	}
}

template<class T>
CMatrice<T>::CMatrice(const unsigned int uiX, const unsigned int uiY) {
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = !(T()); //on initialise chaque element par sa valeur unitaire
		}
	}
}

template<class T>
CMatrice<T>::~CMatrice() {
	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMATelem[uiBoucleFor];
	delete[] ppdMATelem;
};


/*** Autres methodes ***/

template<class T>
void CMatrice<T>::MATprint(const bool bEndl) const {
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) { //affiche les uiMATdimLigne elements de la uiBoucleForX-ieme ligne
			std::cout << ppdMATelem[uiBoucleForX][uiBoucleForY];
			if (uiBoucleForY < uiMATdimColonne) //met un espace seulement entre des elements
				std::cout << "\t";
		}
		if (uiBoucleForX != uiMATdimLigne - 1)
			std::cout << std::endl << std::endl; //saute une ligne seulement entre des elements
	}
	std::cout << std::endl;
	if (bEndl) std::cout << std::endl << std::endl; //revient une 2e fois a la ligne seulement si bEndl est vrai
};

template<class T>
CMatrice<T> CMatrice<T>::MATt() const {
	//init
	CMatrice<T> MATt;
	/*
	 *	Chaque element de coordonnees (x,y) prend la valeur de celui dans MATt de coordonnees (y,x).
	 *	Les dimensions de la matrice sont donc logiquement inversees.
	 */
	MATt.uiMATdimLigne = uiMATdimColonne;
	MATt.uiMATdimColonne = uiMATdimLigne;

	//calcul
	MATt.ppdMATelem = new T*[MATt.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MATt.uiMATdimLigne; uiBoucleForX++) {
		MATt.ppdMATelem[uiBoucleForX] = new T[MATt.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de coordonnees (uiBoucleForY,uiBoucleForX) a (uiBoucleForX,uiBoucleForY) pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MATt.uiMATdimColonne; uiBoucleForY++) {
			MATt.ppdMATelem[uiBoucleForX][uiBoucleForY] = ppdMATelem[uiBoucleForY][uiBoucleForX];
		}
	}
	return MATt;
};
