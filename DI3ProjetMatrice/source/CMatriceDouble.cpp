#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif
#include <iostream>


/*** Constructeurs et destructeurs ***/

CMatriceDouble::CMatriceDouble() {
	ppdMADElem = nullptr;
	uiMATdimLigne = uiMATdimColonne = 0;
}

CMatriceDouble::CMatriceDouble(const CMatriceDouble& MADArg) /*throw(CException)*/ {
	/* Test a mettre dans le constructeur de conversion du template : operator ClassDifferente()
	if (MADArg.ppdMADElem != nullptr) {
		try { (double) MADArg.ppdMADElem[0][0]; }
		catch (...) {
			//CException EXCConversion;
		//EXCConversion.id = 1; //erreur de type 1
		//EXCConversion.comment = "types incompatibles";
			//throw(CException);
		}
	}
	*/
	//init
	uiMATdimLigne = MADArg.uiMATdimLigne;
	uiMATdimColonne = MADArg.uiMATdimColonne;

	//allocation dynamique de chaque ligne
	ppdMADElem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MADArg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADElem[uiBoucleForX][uiBoucleForY] = MADArg.ppdMADElem[uiBoucleForX][uiBoucleForY];
		}
	}
}

CMatriceDouble::CMatriceDouble(const unsigned int uiX, const unsigned int uiY) {
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMADElem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADElem[uiBoucleForX][uiBoucleForY] = 1;
		}
	}
}

CMatriceDouble::~CMatriceDouble() {
	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMADElem[uiBoucleFor];
	delete[] ppdMADElem;
}


/*** Operateurs ***/

CMatriceDouble CMatriceDouble::operator*(const long double clfArg) /*throw(CException)*/ const {
	//Effectuer un try pour lever les erreurs de conversion si type(clfArg) est trop different.
	try { (const double) clfArg; }
	catch (...) {
		//CException EXCConversion;
		//EXCConversion.id = 1; //erreur de type 1
		//EXCConversion.comment = "types incompatibles";
		//throw(CException);
	}

	//init
	CMatriceDouble MADMult = CMatriceDouble();
	MADMult.uiMATdimLigne = uiMATdimLigne;
	MADMult.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADMult.ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADMult.ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat de la multiplication de chaque element par cfConst pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADMult.ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] * clfArg;
		}
	}
	return MADMult;
}

CMatriceDouble CMatriceDouble::operator/(const long double clfArg) /*throw(CException)*/ const {
	//Effectuer un try pour lever les erreurs de conversion si type(clfArg) est trop different.
	try { (const double) clfArg; }
	catch (...) {
		//CException EXCConversion;
		//EXCConversion.id = 1; //erreur de type 1
		//EXCConversion.comment = "types incompatibles";
		//throw(CException);
	}

	//init
	CMatriceDouble MADMult = CMatriceDouble();
	MADMult.uiMATdimLigne = uiMATdimLigne;
	MADMult.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADMult.ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADMult.ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat de la division de chaque element par cfConst pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADMult.ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] / clfArg;
		}
	}
	return MADMult;
}

CMatriceDouble CMatriceDouble::operator+(const CMatriceDouble& MADArg) /*throw(CException)*/ const {
	//Effectuer un try pour lever l'erreur en cas de dimensions differentes entre MADActuelle et MADArg.
	if (uiMATdimLigne != MADArg.uiMATdimLigne) {
		//CException EXCConversion;
		//EXCConversion.id = 2; //erreur de type 1
		//EXCConversion.comment = "mauvais nombre de LIGNES de l'argument";
		//throw(CException);
	}
	if (uiMATdimColonne != MADArg.uiMATdimColonne) {
		//CException EXCConversion;
		//EXCConversion.id = 2; //erreur de type 1
		//EXCConversion.comment = "mauvais nombre de COLONNES de l'argument";
		//throw(CException);
	}

	//init
	CMatriceDouble MADAdd = CMatriceDouble();
	MADAdd.uiMATdimLigne = uiMATdimLigne;
	MADAdd.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADAdd.ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADAdd.ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat pour chaque element de sa somme avec celui aux memes coordonnees dans MADArg, pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADAdd.ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] + MADArg.ppdMADElem[uiBoucleForX][uiBoucleForY];
		}
	}
	return MADAdd;
}

CMatriceDouble CMatriceDouble::operator-(const CMatriceDouble& MADArg) /*throw(CException)*/ const {
	//Effectuer un try pour lever l'erreur en cas de dimensions differentes entre MADActuelle et MADArg.
	if (uiMATdimLigne != MADArg.uiMATdimLigne) {
		//CException EXCConversion;
		//EXCConversion.id = 2; //erreur de type 2
		//EXCConversion.comment = "mauvais nombre de LIGNES de l'argument";
		//throw(CException);
	}
	if (uiMATdimColonne != MADArg.uiMATdimColonne) {
		//CException EXCConversion;
		//EXCConversion.id = 2; //erreur de type 2
		//EXCConversion.comment = "mauvais nombre de COLONNES de l'argument";
		//throw(CException);
	}

	//init
	CMatriceDouble MADSous = CMatriceDouble();
	MADSous.uiMATdimLigne = uiMATdimLigne;
	MADSous.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADSous.ppdMADElem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADSous.ppdMADElem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat pour chaque element de sa soustraction par celui aux memes coordonnees dans MADArg, pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADSous.ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForX][uiBoucleForY] - MADArg.ppdMADElem[uiBoucleForX][uiBoucleForY];
		}
	}
	return MADSous;
}

CMatriceDouble CMatriceDouble::operator*(const CMatriceDouble& MADArg) /*throw(CException)*/ const {
	//Effectuer un try pour lever l'erreur en cas de dimensions incompatibles entre MADActuelle et MADArg :
	if (uiMATdimColonne != MADArg.uiMATdimLigne) {
		//CException EXCConversion;
		//EXCConversion.id = 2; //erreur de type 2
		//EXCConversion.comment = "mauvais nombre de LIGNES de l'argument";
		//throw(CException);
	}
	//Le produit de MAD1 et MAD2 est possible <=> MAD1 est de dimensions NxR et MAD2 est de dimensions RxM. Le produit est alors de taille  MxN.

	//init
	CMatriceDouble MADMult = CMatriceDouble();
	MADMult.uiMATdimLigne = uiMATdimLigne;
	MADMult.uiMATdimColonne = MADArg.uiMATdimColonne;

	//calcul
	MADMult.ppdMADElem = new double*[MADMult.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MADMult.uiMATdimLigne; uiBoucleForX++) {
		MADMult.ppdMADElem[uiBoucleForX] = new double[MADMult.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		/*
		 *	Chaque element de coordonnees (x,y) de la matrice de resultat MADMult est egal
		 *	au produit scalaire de la uiBoucleForX-ieme ligne de MADActuelle par la uiBoucleForY-ieme colonne de MADArg
		 */
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MADMult.uiMATdimColonne; uiBoucleForY++) {

			//pour chaque ligne de MADActuelle
			double dSommeProdScalaireVects = 0;
			//on parcourt la ligne de MADActuelle (soit aussi la colonne de MADArg)
			for (unsigned int uiBoucleForYCalcul = 0; uiBoucleForYCalcul < uiMATdimColonne; uiBoucleForYCalcul++) {
				//on somme le produit de chaque uiBoucleForYCalcul-ieme element
				dSommeProdScalaireVects += ppdMADElem[uiBoucleForX][uiBoucleForYCalcul] * MADArg.ppdMADElem[uiBoucleForYCalcul][uiBoucleForY];
			}
			MADMult.ppdMADElem[uiBoucleForX][uiBoucleForY] = dSommeProdScalaireVects;

		}
	}
	return MADMult;
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
	if (bEndl) std::cout << std::endl << std::endl; //revient une 2e fois a la ligne seulement si bEndl est vrai
}

CMatriceDouble CMatriceDouble::MADt() const {
	//init
	CMatriceDouble MADt = CMatriceDouble();
	/*
	 *	Chaque element de coordonnees (x,y) prend la valeur de celui dans MADt de coordonnees (y,x).
	 *	Les dimensions de la matrice sont donc logiquement inversees.
	 */
	MADt.uiMATdimLigne = uiMATdimColonne;
	MADt.uiMATdimColonne = uiMATdimLigne;

	//calcul
	MADt.ppdMADElem = new double*[MADt.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MADt.uiMATdimLigne; uiBoucleForX++) {
		MADt.ppdMADElem[uiBoucleForX] = new double[MADt.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de coordonnees (uiBoucleForY,uiBoucleForX) a (uiBoucleForX,uiBoucleForY) pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MADt.uiMATdimColonne; uiBoucleForY++) {
			MADt.ppdMADElem[uiBoucleForX][uiBoucleForY] = ppdMADElem[uiBoucleForY][uiBoucleForX];
		}
	}
	return MADt;
}
