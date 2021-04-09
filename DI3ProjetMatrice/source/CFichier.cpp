#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif
#include <fstream>
using namespace std;

/*** Constructeurs et destructeurs ***/

CFichier::CFichier() {
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	pMATDmatrice = nullptr;
}

CFichier::CFichier(CFichier &FICarg) {
	if (FICarg.pcFICnom != nullptr) {
		pcFICnom = FICarg.pcFICnom;
	}
	if (FICarg.pFICfichier != nullptr) {
		pFICfichier = new FILE(*FICarg.pFICfichier);
	}
	if (FICarg.pMATDmatrice != nullptr) {
		pMATDmatrice = new CMatrice<double>(*FICarg.pMATDmatrice);
	}
}

CFichier::CFichier(const char* pcNomFichier) {
	FICsetNomFichier(pcNomFichier);
	FICparcourir();
}

CFichier::~CFichier() {
	delete pFICfichier;
	delete pMATDmatrice;
}


/*** Accesseurs et mutateurs ***/

void CFichier::FICsetNomFichier(const char* pcNomFichier) {
	pcFICnom = pcNomFichier;
}

const char* CFichier::FICgetNomFichier() {
	return pcFICnom;
}

CMatrice<double> CFichier::FICgetCMatrice() {
	return *pMATDmatrice;
}

double CFichier::FICgetCMatriceElem(const unsigned int uiX, const unsigned int uiY) {
	return pMATDmatrice->MATgetElem(uiX, uiY);
}


/*** Operateurs ***/

CFichier& CFichier::operator=(CFichier &FICarg) {
	if (FICarg.pcFICnom != nullptr) {
		pcFICnom = FICarg.pcFICnom;
	}
	if (FICarg.pFICfichier != nullptr) {
		pFICfichier = new FILE(*FICarg.pFICfichier);
	}
	if (FICarg.pMATDmatrice != nullptr) {
		pMATDmatrice = new CMatrice<double>(*FICarg.pMATDmatrice);
	}
	return *this;
}


/*** Autres methodes ***/

void CFichier::FICparcourir() {

	fopen_s(&pFICfichier, pcFICnom, "r");

	//on récupère la première ligne afin de savoir si le type attendu de la matrice est le bon
	char pligneCourante[20];
	fgets(pligneCourante, 20, pFICfichier);
	const char* pcTypeAttendu = "TypeMatrice=double";

	if (*pligneCourante == *(char*)pcTypeAttendu) {
		//on deplace le curseur afin de scanner le nombre de lignes
		unsigned int uiNbLignes;
		fseek(pFICfichier, 9, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbLignes);

		//on deplace le curseur afin de scanner le nombre de colonnes
		unsigned int uiNbColonnes;
		fseek(pFICfichier, 13, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbColonnes);

		//creation de la matrice
		CMatrice<double>* pMATD = new CMatrice<double>(uiNbLignes, uiNbColonnes);

		//on positionne le curseur sur le premier element de la matrice
		fseek(pFICfichier, 11, SEEK_CUR);

		/*on initialise les elements de la matrice creee en memoire a partir
		de ceux du fichier texte */
		double dElement;
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
		printf("CFichier : type attendu incorrect\n");
	}

	//on referme le fichier
	fclose(pFICfichier);
}

void CFichier::FICprintCMatrice() {
	pMATDmatrice->MATprint();
}
