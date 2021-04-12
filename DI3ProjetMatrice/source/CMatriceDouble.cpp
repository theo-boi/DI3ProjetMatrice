#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif
#include <iostream>

/*******************************************************/
/************ Constructeurs et destructeurs ************/
/*******************************************************/

CMatriceDouble::CMatriceDouble() {
	ppdMADelem = nullptr;
	uiMATdimLigne = uiMATdimColonne = 0;
}

CMatriceDouble::CMatriceDouble(const CMatriceDouble& MADArg) throw(CException) {
	//Test a mettre dans le constructeur de conversion du template : operator ClassDifferente()
	if (MADArg.ppdMADelem != nullptr) {
		try { (double) MADArg.ppdMADelem[0][0]; }
		catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
		catch (...) {
			CException EXCconversion;
			EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
			EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
			throw(EXCconversion);
		}
	}
	
	//init
	uiMATdimLigne = MADArg.uiMATdimLigne;
	uiMATdimColonne = MADArg.uiMATdimColonne;

	//allocation dynamique de chaque ligne
	ppdMADelem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MADArg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADelem[uiBoucleForX][uiBoucleForY] = MADArg.ppdMADelem[uiBoucleForX][uiBoucleForY];
		}
	}
}

CMatriceDouble::CMatriceDouble(const unsigned int uiX, const unsigned int uiY) {
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMADelem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADelem[uiBoucleForX][uiBoucleForY] = 1;
		}
	}
}

CMatriceDouble::~CMatriceDouble() {
	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMADelem[uiBoucleFor];
	delete[] ppdMADelem;
}


/*******************************************************/
/********************* Operateurs **********************/
/*******************************************************/

/************* Calculs avec les constantes *************/

CMatriceDouble CMatriceDouble::operator*(const long double lfArg) const throw(CException) {
	//Effectuer un try pour lever les erreurs de conversion si type(clfArg) est trop different.
	try { (const double) lfArg; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("operator* (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	CMatriceDouble MADMult;
	MADMult.uiMATdimLigne = uiMATdimLigne;
	MADMult.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADMult.ppdMADelem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADMult.ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat de la multiplication de chaque element par cfConst pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADMult.ppdMADelem[uiBoucleForX][uiBoucleForY] = ppdMADelem[uiBoucleForX][uiBoucleForY] * lfArg;
		}
	}
	return MADMult; //passage par valeur : MADMult est recopie
}

CMatriceDouble operator*(const long double cldArg, const CMatriceDouble MADArg) throw(CException) {
	//init
	CMatriceDouble MADMult = CMatriceDouble(MADArg);

	//calcul
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MADMult.MATgetDimLigne(); uiBoucleForX++) {
		//calcul de chaque element par vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MADMult.MATgetDimColonne(); uiBoucleForY++) {
			MADMult.MADsetElem(uiBoucleForX, uiBoucleForY, MADMult.MADgetElem(uiBoucleForX, uiBoucleForY)*cldArg);
		}
	}
	return MADMult; //passage par valeur : MADMult est recopie
}

CMatriceDouble CMatriceDouble::operator/(const long double lfArg) const throw(CException) {
	//Effectuer un try pour lever les erreurs de conversion si type(clfArg) est trop different.
	try { (const double) lfArg; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("operator/ (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	CMatriceDouble MADDiv;
	MADDiv.uiMATdimLigne = uiMATdimLigne;
	MADDiv.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADDiv.ppdMADelem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADDiv.ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat de la division de chaque element par cfConst pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADDiv.ppdMADelem[uiBoucleForX][uiBoucleForY] = ppdMADelem[uiBoucleForX][uiBoucleForY] / lfArg;
		}
	}
	return MADDiv; //passage par valeur : MADDiv est recopie
}


/************** Calculs avec les CMatrice **************/

CMatriceDouble CMatriceDouble::operator+(const CMatriceDouble& MADArg) const throw(CException) {
	//Lever une exception en cas de dimensions differentes entre MADActuelle et MADArg.
	if (uiMATdimLigne != MADArg.uiMATdimLigne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator+ (nombre de LIGNES de l'argument incoherent)");
		throw(EXCconversion);
	}
	if (uiMATdimColonne != MADArg.uiMATdimColonne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator+ (nombre de COLONNES de l'argument incoherent)");
		throw(EXCconversion);
	}

	//init
	CMatriceDouble MADAdd;
	MADAdd.uiMATdimLigne = uiMATdimLigne;
	MADAdd.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADAdd.ppdMADelem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADAdd.ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat pour chaque element de sa somme avec celui aux memes coordonnees dans MADArg, pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADAdd.ppdMADelem[uiBoucleForX][uiBoucleForY] = ppdMADelem[uiBoucleForX][uiBoucleForY] + MADArg.ppdMADelem[uiBoucleForX][uiBoucleForY];
		}
	}
	return MADAdd; //passage par valeur : MADAdd est recopie
}

CMatriceDouble CMatriceDouble::operator-(const CMatriceDouble& MADArg) const throw(CException) {
	//Lever une exception en cas de dimensions differentes entre MADActuelle et MADArg.
	if (uiMATdimLigne != MADArg.uiMATdimLigne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator- (nombre de LIGNES de l'argument incoherent)");
		throw(EXCconversion);
	}
	if (uiMATdimColonne != MADArg.uiMATdimColonne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator- (nombre de COLONNES de l'argument incoherent)");
		throw(EXCconversion);
	}

	//init
	CMatriceDouble MADSous;
	MADSous.uiMATdimLigne = uiMATdimLigne;
	MADSous.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MADSous.ppdMADelem = new double*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MADSous.ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat pour chaque element de sa soustraction par celui aux memes coordonnees dans MADArg, pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MADSous.ppdMADelem[uiBoucleForX][uiBoucleForY] = ppdMADelem[uiBoucleForX][uiBoucleForY] - MADArg.ppdMADelem[uiBoucleForX][uiBoucleForY];
		}
	}
	return MADSous; //passage par valeur : MADSous est recopie
}

CMatriceDouble CMatriceDouble::operator*(const CMatriceDouble& MADArg) const throw(CException) {
	//Lever une exception en cas de dimensions incompatibles entre MADActuelle et MADArg :
	if (uiMATdimColonne != MADArg.uiMATdimLigne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator* (nombre de LIGNES de l'argument incoherent)");
		throw(EXCconversion);
	}
	//Le produit de MAD1 et MAD2 est possible <=> MAD1 est de dimensions NxR et MAD2 est de dimensions RxM. Le produit est alors de taille  MxN.

	//init
	CMatriceDouble MADMult;
	MADMult.uiMATdimLigne = uiMATdimLigne;
	MADMult.uiMATdimColonne = MADArg.uiMATdimColonne;

	//calcul
	MADMult.ppdMADelem = new double*[MADMult.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MADMult.uiMATdimLigne; uiBoucleForX++) {
		MADMult.ppdMADelem[uiBoucleForX] = new double[MADMult.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
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
				dSommeProdScalaireVects += ppdMADelem[uiBoucleForX][uiBoucleForYCalcul] * MADArg.ppdMADelem[uiBoucleForYCalcul][uiBoucleForY];
			}
			MADMult.ppdMADelem[uiBoucleForX][uiBoucleForY] = dSommeProdScalaireVects;

		}
	}
	return MADMult; //passage par valeur : MADMult est recopie
}

CMatriceDouble& CMatriceDouble::operator=(const CMatriceDouble& MADArg) throw(CException) {
	//Test a mettre dans le constructeur de conversion du template : operator ClassDifferente()
	if (MADArg.ppdMADelem != nullptr) {
		try { (double) MADArg.ppdMADelem[0][0]; }
		catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
		catch (...) {
			CException EXCconversion;
			EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
			EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
			throw(EXCconversion);
		}
	}

	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMADelem[uiBoucleFor];
	delete[] ppdMADelem;

	//init
	uiMATdimLigne = MADArg.uiMATdimLigne;
	uiMATdimColonne = MADArg.uiMATdimColonne;

	//allocation dynamique de chaque ligne
	ppdMADelem = new double*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMADelem[uiBoucleForX] = new double[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MADArg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMADelem[uiBoucleForX][uiBoucleForY] = MADArg.ppdMADelem[uiBoucleForX][uiBoucleForY];
		}
	}

	return *this; //passage par reference
}


/*******************************************************/
/******************* Autres methodes *******************/
/*******************************************************/

void CMatriceDouble::MATprint(bool bEndl) const {
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) { //affiche les uiMATdimLigne elements de la uiBoucleForX-ieme ligne
			std::cout << ppdMADelem[uiBoucleForX][uiBoucleForY];
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
	CMatriceDouble MADt;
	/*
	 *	Chaque element de coordonnees (x,y) prend la valeur de celui dans MADt de coordonnees (y,x).
	 *	Les dimensions de la matrice sont donc logiquement inversees.
	 */
	MADt.uiMATdimLigne = uiMATdimColonne;
	MADt.uiMATdimColonne = uiMATdimLigne;

	//calcul
	MADt.ppdMADelem = new double*[MADt.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MADt.uiMATdimLigne; uiBoucleForX++) {
		MADt.ppdMADelem[uiBoucleForX] = new double[MADt.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de coordonnees (uiBoucleForY,uiBoucleForX) a (uiBoucleForX,uiBoucleForY) pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MADt.uiMATdimColonne; uiBoucleForY++) {
			MADt.ppdMADelem[uiBoucleForX][uiBoucleForY] = ppdMADelem[uiBoucleForY][uiBoucleForX];
		}
	}
	return MADt; //passage par valeur : MAD2 est recopie
}
