#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main(int argc, char *argv[])
{
	//init
	unsigned int uiNbFichiers = argc-1; //nombre d'arguments entres en parametre de l'executable
	CMatrice<double>** pMATDbdd = new CMatrice<double>*[uiNbFichiers]; //conservation des matrices extraites des fichiers

	if (!uiNbFichiers)
	{
		cout << "Aucun fichier en parametre de l'executable. Veuillez reessayer.\n";
		return EXIT_FAILURE;
	}


	//extraction des matrices depuis les fichiers entres en arguments de l'executable
	unsigned int uiNbFichierDefaillants = 0;
	for (unsigned int uiBoucleArgs = 0; uiBoucleArgs < uiNbFichiers; uiBoucleArgs++)
	{
		try
		{
			CFichier fichier( argv[uiBoucleArgs + 1] ); //instancie un CFichier temporaire et sa CMatrice
			//sauvegarde une copie de la CMatrice dans pMATDbdd
			pMATDbdd[uiBoucleArgs-uiNbFichierDefaillants] = new CMatrice<double>(fichier.FICgetCMatrice());
			pMATDbdd[uiBoucleArgs-uiNbFichierDefaillants]->MATprint(1); //affichage de la matrice
		}
		catch (CException EXCextraction)
		{
			cout << EXCextraction.EXCGetCommentaire() << endl << endl;
			uiNbFichierDefaillants++;
		}
	}
	uiNbFichiers -= uiNbFichierDefaillants;

	if (!uiNbFichiers)
	{
		cout << "Aucun fichier valide en parametre de l'executable. Veuillez reessayer.\n";
		return EXIT_FAILURE; //si il n'y a aucun fichier valide, on n'execute pas la suite du programme
	}


	//affichage dudeterminant de chaque matrice
	for (unsigned int uiBoucleArgs = 0; uiBoucleArgs < uiNbFichiers; uiBoucleArgs++)
	{
		try
		{
			cout << "det(M" << uiBoucleArgs << ") = " << pMATDbdd[uiBoucleArgs]->MATVandermondeDet() << "\n";
		}
		catch (CException EXCextraction)
		{
			cout << endl << EXCextraction.EXCGetCommentaire() << endl << endl;
		}
	}
	
	for (unsigned int uiBoucleDelete = 0; uiBoucleDelete < uiNbFichiers; uiBoucleDelete++)
	{
		delete pMATDbdd[uiBoucleDelete];
	}
	delete[] pMATDbdd;
	return EXIT_SUCCESS;
}
