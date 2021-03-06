#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif
#include <iostream>
using namespace std;


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
		EXCouverture.EXCSetCommentaire("Erreur \"echec d'ouverture du fichier\" dans FICparcourir");
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

	//on teste le format du fichier
	char pNbLignes[20];
	fgets(pNbLignes, 20, pFICfichier);
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < 9; uiBoucleFor++) {
		if (pNbLignes[uiBoucleFor] != "NBLignes="[uiBoucleFor]) {
			formatIncorrect = true;
		}
	}
	
	char pNbColonnes[20];
	fgets(pNbColonnes, 20, pFICfichier);
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < 11; uiBoucleFor++) {
		if (pNbColonnes[uiBoucleFor] != "NBColonnes="[uiBoucleFor]) {
			formatIncorrect = true;
		}
	}


	if (!formatIncorrect) {
		//on deplace le curseur afin de scanner le nombre de lignes
		unsigned int uiNbLignes = 0;
		fseek(pFICfichier, 0, SEEK_SET);
		fgets(pligneCourante, 20, pFICfichier);
		fseek(pFICfichier, 9, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbLignes);

		//gestion exception si pb nb lignes		
		if (pNbLignes[9] < '0' || pNbLignes[9] > '9')
		{
			formatIncorrect = true;
		}

		//on scanne le nombre de colonnes
		unsigned int uiNbColonnes = 0;
		fseek(pFICfichier, 13, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbColonnes);

		//gestion exception si pb nb colonnes
		if (pNbColonnes[11] < '0' || pNbColonnes[11] > '9')
		{
			formatIncorrect = true;
		}

		if (formatIncorrect)
		{
			CException EXCformatContenu;
			EXCformatContenu.EXCSetId(fichier_incompatible); //erreur de type 5
			EXCformatContenu.EXCSetCommentaire("Erreur \"fichier incompatible\" dans FICparcourir() : nombre de lignes ou de colonnes mal renseigne");
			throw(EXCformatContenu);
		}

		//creation de la matrice
		CMatrice<double>* pMATD = new CMatrice<double>(uiNbLignes, uiNbColonnes);

		//on positionne le curseur sur le premier element de la matrice
		fseek(pFICfichier, 11, SEEK_CUR);

		/*on initialise les elements de la matrice creee en memoire a partir
		de ceux du fichier texte */
		double dElement = 0;
		char c;

		for (unsigned int i = 0; i < uiNbLignes; i++) {
			for (unsigned int j = 0; j < uiNbColonnes; j++) {
				fscanf_s(pFICfichier, "%lf", &dElement);
				pMATD->MATsetElem(i, j, dElement);
			}
			c = fgetc(pFICfichier);
			if (c != '\n') { formatIncorrect = true; }
		}

		c = fgetc(pFICfichier);
		if (c != ']') { formatIncorrect = true; }

		//si il y a eu un pb de dimension
		if (formatIncorrect)
		{
			CException EXCformatContenu;
			EXCformatContenu.EXCSetId(fichier_incompatible); //erreur de type 5
			EXCformatContenu.EXCSetCommentaire("Erreur \"fichier incompatible\" dans FICparcourir() : matrice non adaptee");
			throw(EXCformatContenu);
		}

		//on garde la variable MAT dans notre objet CFichier
		pMATDmatrice = pMATD;
	}
	else {
		CException EXCformatContenu;
		EXCformatContenu.EXCSetId(fichier_incompatible); //erreur de type 5
		EXCformatContenu.EXCSetCommentaire("Erreur \"fichier incompatible\" dans FICparcourir() : contenu du fichier incompatible");
		throw(EXCformatContenu);
	}

	//on referme le fichier
	return fclose(pFICfichier);
}
