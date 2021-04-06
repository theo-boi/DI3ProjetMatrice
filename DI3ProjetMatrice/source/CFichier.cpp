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
	CMatriceDouble MAD;
	char pligneCourante[20];

	fgets(pligneCourante, 20, pFICfichier);
	puts(pligneCourante);	

	const char* pcTypeAttendu = "TypeMatrice=double";
	
	if (*pligneCourante == *(char*)pcTypeAttendu)
	{
		printf("CFichier : type attendu correct\n");
	}
	else
	{
		printf("CFichier : type attendu incorrect\n");
	}
	pcFICnom = nullptr;
}
