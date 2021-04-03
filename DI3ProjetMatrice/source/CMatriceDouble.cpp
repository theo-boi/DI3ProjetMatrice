#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif
#include <iostream>


/*** Constructeurs et destructeurs ***/

CMatriceDouble::CMatriceDouble() {
	ppdMAIElem = nullptr;
	eMATdimLigne = eMATdimColonne = 0;
}

CMatriceDouble::CMatriceDouble(unsigned int eArgX, unsigned int eArgY) {
	eMATdimLigne = eArgX;
	eMATdimColonne = eArgY;
	ppdMAIElem = new double*[eMATdimLigne];
	for (unsigned int eBoucleForX = 0; eBoucleForX < eMATdimLigne; eBoucleForX++) {
		ppdMAIElem[eBoucleForX] = new double[eMATdimColonne];
		for (unsigned int eBoucleForY = 0; eBoucleForY < eMATdimColonne; eBoucleForY++) {
			ppdMAIElem[eBoucleForX][eBoucleForY] = 0;
		}
	}
}

CMatriceDouble::~CMatriceDouble() {
	for (unsigned int eBoucleFor = 0; eBoucleFor < eMATdimLigne; eBoucleFor++)
		delete[] ppdMAIElem[eBoucleFor];
	delete[] ppdMAIElem;
}


/*** Operateurs ***/



/*** Methodes ***/

/*
	Entree : x : entier non signe, y : entier non signe
	Precondition : neant
	Sortie : dMAIElem : double
	Postcondition : (dMAIElem = ppdMAIElem[x][y])^(x < eMATdimLigne)^(y < eMATdimLigne)
*/
double CMatriceDouble::MATGet(unsigned int x, unsigned int y) {
	if (x >= eMATdimLigne && y >= eMATdimLigne) {
		/* exception */;
	}
	return ppdMAIElem[x][y];
}

/*
	Entree : rien
	Precondition : neant
	Sortie : rien
	Postcondition : Affiche les elements de CMatriceDouble
*/
void CMatriceDouble::MATPrint() {
	for (unsigned int eBoucleForX = 0; eBoucleForX < eMATdimLigne; eBoucleForX++) {
		for (unsigned int eBoucleForY = 0; eBoucleForY < eMATdimLigne; eBoucleForY++) {
			std::cout << ppdMAIElem[eBoucleForX][eBoucleForY];
			if (eBoucleForY != eMATdimColonne - 1)
				std::cout << ' ';
		}
		if (eBoucleForX != eMATdimLigne - 1)
			std::cout << std::endl;
	}
}