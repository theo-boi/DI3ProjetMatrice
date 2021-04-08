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


CFichier::CFichier(CFichier &FICarg)
{
	if (FICarg.pcFICnom != nullptr)
	{
		pcFICnom = new char(*FICarg.pcFICnom);
	}
	else
	{
		pcFICnom = nullptr;
	}
	if (FICarg.pFICfichier != nullptr)
	{
		pFICfichier = new FILE(*FICarg.pFICfichier);
	}
	else
	{
		pFICfichier = nullptr;
	}
	if (FICarg.pMADmatrice != nullptr)
	{
		pMADmatrice = new CMatriceDouble(*FICarg.pMADmatrice);
	}
	else
	{
		pMADmatrice = nullptr;
	}
}


CFichier::~CFichier()
{
	delete pFICfichier;
	delete pMADmatrice;
}

//Fonction principale
void CFichier::FICprincipale(const char* pcNomFichier)
{
	pcFICnom = (char*)pcNomFichier;
	
	fopen_s(&pFICfichier, pcFICnom, "r");
	fseek(pFICfichier, 0, SEEK_SET); //cette ligne est-elle vraiment utile ?
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

	//on referme le fichier
	fclose(pFICfichier);
}

//opérateurs

CFichier& CFichier::operator=(CFichier &FICarg)
{
	if (FICarg.pcFICnom != nullptr)
	{
		pcFICnom = new char(*FICarg.pcFICnom);
	}
	else
	{
		pcFICnom = nullptr;
	}
	if (FICarg.pFICfichier != nullptr)
	{
		pFICfichier = new FILE(*FICarg.pFICfichier);
	}
	else
	{
		pFICfichier = nullptr;
	}
	if (FICarg.pMADmatrice != nullptr)
	{
		pMADmatrice = new CMatriceDouble(*FICarg.pMADmatrice);
	}
	else
	{
		pMADmatrice = nullptr;
	}
	return *this;
}
