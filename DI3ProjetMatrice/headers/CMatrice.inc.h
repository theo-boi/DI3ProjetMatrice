#ifndef CMATRICEH
#include "CMatrice.h"
#endif

/*** Constructeurs et destructeurs ***/

template<class T>
CMatrice<T>::CMatrice() {
	ppdMATelem = nullptr;
}

template<class T>
CMatrice<T>::CMatrice(const CMatrice<T>& MAT2arg) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (T) MAT2arg.MATgetElem(0,0); }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
		throw(EXCconversion);
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
			ppdMATelem[uiBoucleForX][uiBoucleForY] = (T) MAT2arg.MATgetElem(uiBoucleForX, uiBoucleForY);
		}
	}
}

template<class T>
CMatrice<T>::CMatrice(const unsigned int uiX, const unsigned int uiY) {
	//init
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = T(); //on initialise chaque element par sa valeur d'initialisation
		}
	}
}

template<class T> template<class T2>
CMatrice<T>::CMatrice(const unsigned int uiX, const unsigned int uiY, T2 T2elem) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (T) T2elem; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("MATsetElem (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = (T) T2elem; //on initialise chaque element par sa valeur d'initialisation
		}
	}
}


template<class T>
CMatrice<T>::~CMatrice() {
	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMATelem[uiBoucleFor];
	delete[] ppdMATelem;
}


/*** Accesseurs et mutateurs ***/

template<class T>
T CMatrice<T>::MATgetElem(const unsigned int uiArgX, const unsigned int uiArgY) const throw(CException) {
	//Leve l'exception de conversion si uiArgX ou uiArgY sont trop grands
	if (uiArgX >= uiMATdimLigne || uiArgY >= uiMATdimColonne) {
		CException EXCdimension;
		EXCdimension.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCdimension.EXCSetCommentaire("MATgetElem (valeurs des arguments incompatibles)");
		throw(EXCdimension);
	}

	return ppdMATelem[uiArgX][uiArgY];
}

template<class T> template<class T2>
void CMatrice<T>::MATsetElem(const unsigned int uiArgX, const unsigned int uiArgY, T2 T2elem) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (T) T2elem; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("MATsetElem (type de l'argument incompatible)");
		throw(EXCconversion);
	}
	//Effectuer un try pour lever les erreurs de conversion si uiX ou uiY sont trop grands
	if (uiArgX >= uiMATdimLigne || uiArgY >= uiMATdimColonne) {
		CException EXCdimension;
		EXCdimension.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCdimension.EXCSetCommentaire("MATsetElem (valeurs des arguments incompatibles)");
		throw(EXCdimension);
	}

	//set
	ppdMATelem[uiArgX][uiArgY] = (T) T2elem;
}


/*** Operateurs ***/

template<class T>
CMatrice<T>& CMatrice<T>::operator=(const CMatrice<T>& MAT2arg) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (T) MAT2arg.MATgetElem(0, 0); }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMATelem[uiBoucleFor];
	delete[] ppdMATelem;

	//init
	uiMATdimLigne = MAT2arg.MATgetDimLigne();
	uiMATdimColonne = MAT2arg.MATgetDimColonne();

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MATarg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = (T) MAT2arg.MATgetElem(uiBoucleForX, uiBoucleForY);
		}
	}

	return *this; //passage par reference
}



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
}

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
}
