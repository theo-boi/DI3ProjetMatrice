#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif


// Constructeurs et destructeur

CFichier::CFichier()
{
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	pMADmatrice = nullptr;
}

CFichier::CFichier(const char* pcFICnomFichier)
{
	pcFICnom = pcFICnomFichier;
	fopen_s(&pFICfichier, pcFICnomFichier, "r");
	pMADmatrice = nullptr;

}

CFichier::~CFichier()
{
	delete pcFICnom;
	delete pFICfichier;
	delete pMADmatrice;
}

//Fonction principale
void CFichier::FICprincipale()
{
	CMatriceDouble MAD;
	char* pligneCourante = nullptr;
	fgets(pligneCourante, 200, pFICfichier);
	if (pligneCourante == "TypeMatrice=double")
	{
		printf("CFichier : type attendu correct\n");
	}
	else
	{
		printf("CFichier : type attendu incorrect\n");
	}
}
