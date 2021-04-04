#ifndef CFICHIERH
#include "../headers/CFichier.h"
#endif


// Constructeur et destructeur

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
/*CMatriceDouble CFichier::FICprincipale(char* pcFICnomFichier)
{
	pcFICnom = pcFICnomFichier;
	fopen_s(&pFICfichier, pcFICnomFichier, "r");
	CMatriceDouble MAD;
	char* pligneCourante;
	fgets(pligneCourante, 200, pFICfichier);
	if (pligneCourante == "TypeMatrice=double")
	{
		printf("CFichier : type attendu correct");
	}
	return MAD;
}*/
