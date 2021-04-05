#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif
#include <iostream>


/*** Constructeurs et destructeurs ***/

CMatriceDouble::CMatriceDouble() {
	ppdMADElem = nullptr;
	uiMATdimLigne = uiMATdimColonne = 0;
}

CMatriceDouble::CMatriceDouble(const CMatriceDouble& MADArg) {
	uiMATdimLigne = MADArg.uiMATdimLigne;
	uiMATdimColonne = MADArg.uiMATdimColonne;

	//allocation dynamique de chaque vecteur d'elements
	ppdMADElem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//recopie chaque element de MADArg par vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADElem[uiBoucleForX][uiBoucleForY] = MADArg.ppdMADElem[uiBoucleForX][uiBoucleForY];
		}
	}
}

CMatriceDouble::CMatriceDouble(const unsigned int uiX, const unsigned int uiY) {
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque vecteur d'elements
	ppdMADElem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//initialisation de chaque element a 1 par vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADElem[uiBoucleForX][uiBoucleForY] = 1;
		}
	}
}

CMatriceDouble::~CMatriceDouble() {
	//liberation de chaque vecteur de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMADElem[uiBoucleFor];
	delete[] ppdMADElem;
}


/*** Operateurs ***/

CMatriceDouble& CMatriceDouble::operator*(const long double clfArg) const {
	//init	
	//SI MISE EN PLACE D'UN TEMPLATE : Effectuer un try pour lever les erreurs de conversion si type(clfArg) est trop different.
	const double cfConst = (const double) clfArg;

	CMatriceDouble* pMADMult = new CMatriceDouble();
	pMADMult->uiMATdimLigne = uiMATdimLigne;
	pMADMult->uiMATdimColonne = uiMATdimColonne;

	//calcul
	pMADMult->ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque vecteur d'elements
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		pMADMult->ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//recopie le resultat de la multiplication de chaque element par cfConst pour chaque vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			pMADMult->ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] * cfConst;
		}
	}
	return *pMADMult;
}

CMatriceDouble& CMatriceDouble::operator/(const long double clfArg) const {
	//init	
	//SI MISE EN PLACE D'UN TEMPLATE : Effectuer un try pour lever les erreurs de conversion si type(clfArg) est trop different.
	const double cfConst = (const double) clfArg;

	CMatriceDouble* pMADMult = new CMatriceDouble();
	pMADMult->uiMATdimLigne = uiMATdimLigne;
	pMADMult->uiMATdimColonne = uiMATdimColonne;

	//calcul
	pMADMult->ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque vecteur d'elements
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		pMADMult->ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//recopie le resultat de la division de chaque element par cfConst pour chaque vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			pMADMult->ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] / cfConst;
		}
	}
	return *pMADMult;
}


/*** Autres methodes ***/

void CMatriceDouble::MATPrint(bool bEndl) const {
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) { //affiche les uiMATdimLigne elements de la uiBoucleForX-ieme ligne
			std::cout << ppdMADElem[uiBoucleForX][uiBoucleForY];
			if (uiBoucleForY < uiMATdimColonne) //met un espace seulement entre des elements
				std::cout << "\t";
		}
		if (uiBoucleForX != uiMATdimLigne - 1)
			std::cout << std::endl << std::endl; //saute une ligne seulement entre des elements
	}
	std::cout << std::endl;
	if (bEndl) std::cout << std::endl; //revient une 2e fois a la ligne seulement si bEndl est vrai
}

CMatriceDouble& CMatriceDouble::MADt() const {
	//init
	CMatriceDouble* pMADt = new CMatriceDouble();
	/*
	 *	Chaque element de coordonnees (x,y) prend la valeur de celui dans MADt de coordonnees (y,x).
	 *	Les dimensions de la matrice sont donc logiquement inversees.
	 */
	pMADt->uiMATdimLigne = uiMATdimColonne;
	pMADt->uiMATdimColonne = uiMATdimLigne;

	//calcul
	pMADt->ppdMADElem = new double*[pMADt->uiMATdimLigne]; //allocation dynamique de chaque vecteur d'elements
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < pMADt->uiMATdimLigne; uiBoucleForX++) {
		pMADt->ppdMADElem[uiBoucleForX] = new double[pMADt->uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//recopie chaque element de coordonnees (uiBoucleForY,uiBoucleForX) a (uiBoucleForX,uiBoucleForY) pour chaque vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < pMADt->uiMATdimColonne; uiBoucleForY++) {
			pMADt->ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForY][uiBoucleForX];
		}
	}
	return *pMADt;
}

CMatriceDouble& CMatriceDouble::MADAdd(const CMatriceDouble& MADArg) const {
	//Effectuer un try pour lever l'erreur en cas de dimensions differentes entre MADActuelle et MADArg.

	//init
	CMatriceDouble* pMADAdd = new CMatriceDouble();
	pMADAdd->uiMATdimLigne = uiMATdimLigne;
	pMADAdd->uiMATdimColonne = uiMATdimColonne;

	//calcul
	pMADAdd->ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque vecteur d'elements
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		pMADAdd->ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//recopie le resultat pour chaque element de sa somme avec celui aux memes coordonnees dans MADArg, pour chaque vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			pMADAdd->ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] + MADArg.ppdMADElem[uiBoucleForX][uiBoucleForY];
		}
	}
	return *pMADAdd;
}

CMatriceDouble& CMatriceDouble::MADSous(const CMatriceDouble& MADArg) const {
	//Effectuer un try pour lever l'erreur en cas de dimensions differentes entre MADActuelle et MADArg.

	//init
	CMatriceDouble* pMADSous = new CMatriceDouble();
	pMADSous->uiMATdimLigne = uiMATdimLigne;
	pMADSous->uiMATdimColonne = uiMATdimColonne;

	//calcul
	pMADSous->ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque vecteur d'elements
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		pMADSous->ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		//recopie le resultat pour chaque element de sa somme avec celui aux memes coordonnees dans MADArg, pour chaque vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			pMADSous->ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] - MADArg.ppdMADElem[uiBoucleForX][uiBoucleForY];
		}
	}
	return *pMADSous;
}

CMatriceDouble& CMatriceDouble::MADMult(const CMatriceDouble& MADArg) const {
	//Effectuer un try pour lever l'erreur en cas de dimensions incompatibles entre MADActuelle et MADArg :
	//Le produit de MAD1 et MAD2 est possible <=> MAD1 est de dimensions NxR et MAD2 est de dimensions RxM. Le produit est alors de taille  MxN.

	//init
	CMatriceDouble* pMADMult = new CMatriceDouble();
	pMADMult->uiMATdimLigne = uiMATdimLigne;
	pMADMult->uiMATdimColonne = MADArg.uiMATdimColonne;

	//calcul
	pMADMult->ppdMADElem = new double*[pMADMult->uiMATdimLigne]; //allocation dynamique de chaque vecteur d'elements
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < pMADMult->uiMATdimLigne; uiBoucleForX++) {
		pMADMult->ppdMADElem[uiBoucleForX] = new double[pMADMult->uiMATdimColonne]; //allocation dynamique du contenu de chaque vecteur
		/*
		 *	Chaque element de coordonnees (x,y) de la matrice de resultat MADMult est egal
		 *	au produit scalaire de la uiBoucleForX-ieme ligne de MADActuelle par la uiBoucleForY-ieme colonne de MADArg
		 */
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < pMADMult->uiMATdimColonne; uiBoucleForY++) {

			//pour chaque ligne de MADActuelle
			double dSommeProdScalaireVects = 0;
			//on parcourt la ligne de MADActuelle (soit aussi la colonne de MADArg)
			for (unsigned int uiBoucleForYCalcul = 0; uiBoucleForYCalcul < uiMATdimColonne; uiBoucleForYCalcul++) {
				//on somme le produit de chaque uiBoucleForYCalcul-ieme element
				dSommeProdScalaireVects += ppdMADElem[uiBoucleForX][uiBoucleForYCalcul] * MADArg.ppdMADElem[uiBoucleForYCalcul][uiBoucleForY];
			}
			pMADMult->ppdMADElem[uiBoucleForX][uiBoucleForY] = dSommeProdScalaireVects;

		}
	}
	return *pMADMult;
}

