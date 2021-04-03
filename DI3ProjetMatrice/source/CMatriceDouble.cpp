#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif
#include <iostream>


/*** Constructeurs et destructeurs ***/

CMatriceDouble::CMatriceDouble() {
	ppdMAIElem = nullptr;
	uiMATdimLigne = uiMATdimColonne = 0;
}

CMatriceDouble::CMatriceDouble(unsigned int uiX, unsigned int uiY) {
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;
	//allocation dynamique de chaque vecteur d'elements
	ppdMAIElem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMAIElem[uiBoucleForX] = new double[uiMATdimColonne];
		//initialisation de chaque element a 0
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMAIElem[uiBoucleForX][uiBoucleForY] = 0;
		}
	}
}

CMatriceDouble::CMatriceDouble(CMatriceDouble& MADArg) {
	uiMATdimLigne = MADArg.uiMATdimLigne;
	uiMATdimColonne = MADArg.uiMATdimColonne;
	//allocation dynamique de chaque vecteur d'elements
	ppdMAIElem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMAIElem[uiBoucleForX] = new double[uiMATdimColonne];
		//recopie de chaque element de MADArg
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMAIElem[uiBoucleForX][uiBoucleForY] = MADArg.ppdMAIElem[uiBoucleForX][uiBoucleForY];
		}
	}
}

CMatriceDouble::~CMatriceDouble() {
	//liberation des vecteurs de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMAIElem[uiBoucleFor];
	delete[] ppdMAIElem;
}


/*** Operateurs ***/




/*** Autres methodes ***/

void CMatriceDouble::MATPrint() {
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimLigne; uiBoucleForY++) { //affiche les uiMATdimLigne elements de la uiBoucleForX-ieme ligne
			std::cout << ppdMAIElem[uiBoucleForX][uiBoucleForY];
			if (uiBoucleForY != uiMATdimColonne - 1) //met un espace seulement entre des elements
				std::cout << ' ';
		}
		if (uiBoucleForX != uiMATdimLigne - 1)
			std::cout << std::endl; //saute une ligne seulement entre des elements
	}
}
