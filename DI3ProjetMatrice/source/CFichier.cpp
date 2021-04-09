#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif

#include <iostream>
#include <fstream>

using namespace std;


// CONSTRUCTEURS ET DESTRUCTEUR

CFichier::CFichier()
{
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	pMATDmatrice = nullptr;
}


CFichier::CFichier(CFichier &FICarg)
{
	if (FICarg.pcFICnom != nullptr)
	{
		pcFICnom = new const char(*FICarg.pcFICnom);
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
	if (FICarg.pMATDmatrice != nullptr)
	{
		pMATDmatrice = new CMatrice<double>(*FICarg.pMATDmatrice);
	}
	else
	{
		pMATDmatrice = nullptr;
	}
}

CFichier::CFichier(const char* pcNomFichier)
{
	FICsetNomFichier(pcNomFichier);
	FICprincipale();
}


CFichier::~CFichier()
{
	delete pFICfichier;
	delete pMATDmatrice;
}

//ACCESSEURS

void CFichier::FICsetNomFichier(const char* pcNomFichier)
{
	pcFICnom = pcNomFichier;
}


const char* CFichier::FICgetNomFichier()
{
	return pcFICnom;
}

CMatrice<double> CFichier::FICgetMatrice()
{
	return *pMATDmatrice;
}

double CFichier::FICgetMatriceElement(const unsigned int uiX, const unsigned int uiY)
{
	return pMATDmatrice->MATgetElem(uiX, uiY);
}


//FONCTION PRINCIPALE
void CFichier::FICprincipale()
{

	fopen_s(&pFICfichier, pcFICnom, "r");

	//on récupère la première ligne afin de savoir si le type attendu de la matrice est le bon
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
		CMatrice<double>* pMATD = new CMatrice<double>(uiNbLignes, uiNbColonnes);
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
				pMATD->MATsetElem(i, j, dElement);
			}
		}
		//on garde la variable MAD dans notre objet CFichier
		pMATDmatrice = pMATD;
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
	if (FICarg.pMATDmatrice != nullptr)
	{
		pMATDmatrice = new CMatrice<double>(*FICarg.pMATDmatrice);
	}
	else
	{
		pMATDmatrice = nullptr;
	}
	return *this;
}
