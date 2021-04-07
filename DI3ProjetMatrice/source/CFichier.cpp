#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif

#include <iostream>
#include <fstream>

using namespace std;


// Constructeurs et destructeur

CFichier::CFichier()
{
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	pMADmatrice = nullptr;
}


CFichier::~CFichier()
{
	delete pcFICnom;
	delete pFICfichier;
	delete pMADmatrice;
}

//Fonction principale
void CFichier::FICprincipale(const char* pcNomFichier)
{
	pcFICnom = (char*)pcNomFichier;
	
	fopen_s(&pFICfichier, pcFICnom, "r");
	char pligneCourante[20];

	fgets(pligneCourante, 20, pFICfichier);	

	const char* pcTypeAttendu = "TypeMatrice=double";
	
	if (*pligneCourante == *(char*)pcTypeAttendu)
	{		
		unsigned int uiNbLignes;
		unsigned int uiNbColonnes;

		//on deplace le curseur afin de scanner le nombre de lignes
		fseek(pFICfichier, 9, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbLignes);

		//on deplace le curseur afin de scanner le nombre de colonnes
		fseek(pFICfichier, 13, SEEK_CUR);
		fscanf_s(pFICfichier, "%u", &uiNbColonnes);

		//creation de la matrice
		CMatriceDouble* pMAD = new CMatriceDouble(uiNbLignes, uiNbColonnes);
		double dElement;

		//on positionne le curseur sur le premier element de la matrice
		fseek(pFICfichier, 11, SEEK_CUR);

		/*on initialise les elements de la matrice creee en memoire a partir
		de ceux du fichier texte */
		for (unsigned int i = 0; i < uiNbLignes; i++)
		{
			for (unsigned int j = 0; j < uiNbColonnes; j++)
			{
				fscanf_s(pFICfichier, "%lf", &dElement);
				pMAD->MADSetElem(i, j, dElement);
			}
		}
		//on garde la variable MAD dans notre objet CFichier
		pMADmatrice = pMAD;
	}
	else
	{
		printf("CFichier : type attendu incorrect\n");
	}
	////////////////////////////////////!!!!!!! Problème ligne du dessous !!!!!!/////////////////////////////
	pcFICnom = nullptr;

	//on replace le curseur au debut du fichier
	fseek(pFICfichier, 0, SEEK_SET);
}
