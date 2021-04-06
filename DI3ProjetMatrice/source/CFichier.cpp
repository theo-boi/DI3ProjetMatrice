#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif

#include <iostream>
#include <fstream>


// Constructeurs et destructeur

CFichier::CFichier()
{
	pcFICnom = nullptr;
	pFICfichier = nullptr;
	pMADmatrice = nullptr;
}

CFichier::CFichier(const char* pcFICnomFichier)
{
	//pcFICnom = (char*)&pcFICnomFichier;
	pcFICnom = nullptr;
	fopen_s(&pFICfichier, pcFICnomFichier, "r");
	pMADmatrice = nullptr;
	//FILE* file;
	//fopen_s(&file, filename, "r");

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
	char *pligneCourante;
	fscanf_s(pFICfichier, "%s", &pligneCourante, 256);
	//fread(&pligneCourante, sizeof(char), 25, pFICfichier);
	if (pligneCourante == "TypeMatrice=double")
	{
		printf("CFichier : type attendu correct\n");
	}
	else
	{
		printf("CFichier : type attendu incorrect\n");
	}
}
