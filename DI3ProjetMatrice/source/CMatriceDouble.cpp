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
		ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne];
		//recopie de chaque element de MADArg par vecteur
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
		ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne];
		//initialisation de chaque element a 0 par vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADElem[uiBoucleForX][uiBoucleForY] = 0;
		}
	}
}

CMatriceDouble::~CMatriceDouble() {
	//liberation des vecteurs de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMADElem[uiBoucleFor];
	delete[] ppdMADElem;
}


/*** Operateurs ***/

CMatriceDouble& CMatriceDouble::operator*(const long double clfArg) {
	//init	
	//SI MISE EN PLACE D'UN TEMPLATE : Effectuer un try pour lever les erreurs de conversion si type(Arg) est trop different
	const double cfConst = (const double) clfArg;

	CMatriceDouble* pMADMult = new CMatriceDouble(*this);

	//calcul
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			pMADMult->ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] * cfConst;
		}
	}
	return *pMADMult;
}


/*** Autres methodes ***/

void CMatriceDouble::MATPrint(bool bEndl) {
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimLigne; uiBoucleForY++) { //affiche les uiMATdimLigne elements de la uiBoucleForX-ieme ligne
			std::cout << ppdMADElem[uiBoucleForX][uiBoucleForY];
			if (uiBoucleForY != uiMATdimColonne - 1) //met un espace seulement entre des elements
				std::cout << '\t';
		}
		if (uiBoucleForX != uiMATdimLigne - 1)
			std::cout << std::endl << std::endl; //saute une ligne seulement entre des elements
	}
	std::cout << std::endl;
	if (bEndl) std::cout << std::endl; //revient une 2e fois a la ligne seulement si bEndl est vrai
}
