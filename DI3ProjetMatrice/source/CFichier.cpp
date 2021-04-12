#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif
#include <iostream>
using namespace std;

#define echec_ouverture_fichier 4 

#define fichier_incompatible 5


/*******************************************************/
/************ Constructeurs et destructeurs ************/
/*******************************************************/

CFichier::CFichier() {
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	pMATDmatrice = nullptr;
}

CFichier::CFichier(CFichier &FICarg) {
	if (FICarg.pcFICnom != nullptr)
		pcFICnom = FICarg.pcFICnom;
	if (FICarg.pFICfichier != nullptr)
		pFICfichier = FICarg.pFICfichier;
	if (FICarg.pMATDmatrice != nullptr)
		pMATDmatrice = new CMatrice<double>(*FICarg.pMATDmatrice);
}

CFichier::CFichier(const char* pcNomFichier) {
	//init
	pcFICnom = pcNomFichier;
	pFICfichier = nullptr;
	pMATDmatrice = nullptr;

	//extrait CMatrice<double>, donne une valeur aux deux precedents attributs
	FICparcourir();
}

CFichier::~CFichier() {
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	delete pMATDmatrice;
}


/*******************************************************/
/********************* Operateurs **********************/
/*******************************************************/

CFichier& CFichier::operator=(CFichier &FICarg) {
	//del
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	delete pMATDmatrice;

	//reinit
	if (FICarg.pcFICnom != nullptr)
		pcFICnom = FICarg.pcFICnom;
	if (FICarg.pFICfichier != nullptr)
		pFICfichier = FICarg.pFICfichier;
	if (FICarg.pMATDmatrice != nullptr)
		pMATDmatrice = new CMatrice<double>(*FICarg.pMATDmatrice);
	
	return *this;
}


/*******************************************************/
/******************* Autres methodes *******************/
/*******************************************************/

int CFichier::FICparcourir() throw(CException) {
	//init
	fopen_s(&pFICfichier, pcFICnom, "r");

	//Leve une exception si l'ouverture du fichier a rencontre un probleme
	if (!pFICfichier) {
		CException EXCouverture;
		EXCouverture.EXCSetId(echec_ouverture_fichier); //erreur de type 4
		EXCouverture.EXCSetCommentaire("FICparcourir : ouverture du fichier impossible");
		throw(EXCouverture);
	}

	//on recupere la premiere ligne afin de savoir si le type attendu de la matrice est le bon
	char pligneCourante[20];
	fgets(pligneCourante, 20, pFICfichier);

	bool formatIncorrect = false;
	
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < 20; uiBoucleFor++) {
		if (pligneCourante[uiBoucleFor] != "TypeMatrice=double\n"[uiBoucleFor]) {
			formatIncorrect = true;
		}
	}

	if (!formatIncorrect) {
		//on deplace le curseur afin de scanner le nombre de lignes
		unsigned int uiNbLignes = 0;
		fseek(pFICfichier, 9, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbLignes);

		//on deplace le curseur afin de scanner le nombre de colonnes
		unsigned int uiNbColonnes = 0;
		fseek(pFICfichier, 13, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbColonnes);

		//creation de la matrice
		CMatrice<double>* pMATD = new CMatrice<double>(uiNbLignes, uiNbColonnes);

		//on positionne le curseur sur le premier element de la matrice
		fseek(pFICfichier, 11, SEEK_CUR);

		/*on initialise les elements de la matrice creee en memoire a partir
		de ceux du fichier texte */
		double dElement = 0;
		for (unsigned int i = 0; i < uiNbLignes; i++) {
			for (unsigned int j = 0; j < uiNbColonnes; j++) {
				fscanf_s(pFICfichier, "%lf", &dElement);
				pMATD->MATsetElem(i, j, dElement);
			}
		}
		//on garde la variable MAT dans notre objet CFichier
		pMATDmatrice = pMATD;
	}
	else {
		CException EXCformatContenu;
		EXCformatContenu.EXCSetId(fichier_incompatible); //erreur de type 5
		EXCformatContenu.EXCSetCommentaire("FICparcourir() : contenu du fichier incompatible");
		throw(EXCformatContenu);
	}

	//on referme le fichier
	return fclose(pFICfichier);
}
