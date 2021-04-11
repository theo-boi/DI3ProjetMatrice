#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main(int argc, char *argv[]) {
	/*
	//tests CMatrice
	CMatriceTestGlobal();
	//tests CFichier
	CFichierTest();
	*/
	
	//init
	unsigned int uiNbFichiers = argc - 1; //nombre d'arguments entres en parametre de l'executable
	CMatrice<double>* pMATDbdd = new CMatrice<double>[uiNbFichiers]; //conservation des matrices extraites des fichiers

	if (!uiNbFichiers) {
		cout << "Aucun fichier en parametre de l'executable. Veuillez reessayer.\n";
		return 1;
	}


	//extraction des matrices depuis les fichiers entres en arguments de l'executable
	for (unsigned int uiBoucleArgs = 0; uiBoucleArgs < uiNbFichiers; uiBoucleArgs++)
		try {
			CFichier fichier( argv[uiBoucleArgs+1] ); //instancie un CFichier temporaire et sa CMatrice
			pMATDbdd[uiBoucleArgs] = fichier.FICgetCMatrice(); //sauvegarde la CMatrice dans pMATDbdd
		}
		catch (CException EXCextraction) {
			EXCextraction.EXCGestionaireException();
			cout << endl;
			uiBoucleArgs--; uiNbFichiers--; //on considere un fichier de moins
		}

	//affichage de chaque matrice
	cout << "Matrices de vos fichiers entres en arguments :\n\n";
	for (unsigned int uiBoucleBdd = 0; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++)
		pMATDbdd[uiBoucleBdd].MATprint(1);
	
	//initialisation de c
	double dConstante;
	cout << "Entrez une constante c = "; cin >> dConstante; cout << "\n\n\n";


	//affichage du resultat de la multiplication de chaque matrice par la valeur dConstante : c*M
	cout << "Pour chaque matrice M, resultat de c*M :\n\n";
	for (unsigned int uiBoucleBdd = 0; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++)
		try { (dConstante * pMATDbdd[uiBoucleBdd]).MATprint(1); }
		catch (CException EXCmultConst) { EXCmultConst.EXCGestionaireException(); }

	//affichage du resultat de la division de chaque matrice par la valeur dConstante : M/c
	cout << "\nPour chaque matrice M, resultat de M/c :\n\n";
	for (unsigned int uiBoucleBdd = 0; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++)
		try { (pMATDbdd[uiBoucleBdd] / dConstante).MATprint(1); }
		catch (CException EXCdivConst) { EXCdivConst.EXCGestionaireException(); }


	//affichage du resultat de la somme des matrices : M1+M2+M3+...
	cout << "\nSomme des matrices";
	CMatrice<double> MATDsomme(pMATDbdd[0]); //on a au moins une matrice
	try {
		for (unsigned int uiBoucleBdd = 1; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++)
			MATDsomme = MATDsomme + pMATDbdd[uiBoucleBdd];
		cout << " = \n\n";
		MATDsomme.MATprint(1);
	}
	catch (CException EXCsomme) {
		cout << endl;
		EXCsomme.EXCGestionaireException();
	}

	//affichage du resultat de l'operation : M1-M2+M3-M4+M5-M6+...
	cout << "\nSomme alternee des matrices";
	CMatrice<double> MATDsommeAlternee(pMATDbdd[0]); //on a au moins une matrice
	try {
	for (unsigned int uiBoucleBdd = 1; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++)
		if ( uiBoucleBdd % 2 )
			MATDsommeAlternee = MATDsommeAlternee - pMATDbdd[uiBoucleBdd];
		else
			MATDsommeAlternee = MATDsommeAlternee + pMATDbdd[uiBoucleBdd];
		cout << " = \n\n";
		MATDsommeAlternee.MATprint(1);
	}
	catch (CException EXCsommeAlt) {
		cout << endl;
		EXCsommeAlt.EXCGestionaireException();
	}

	//affichage du resultat du produit des matrices : M1xM2xM3x...
	cout << "\nProduit des matrices";
	CMatrice<double> MATDproduit(pMATDbdd[0]); //on a au moins une matrice
	try {
		//le sens de l'operation est important lors d'un produit matriciel
		for (unsigned int uiBoucleBdd = 1; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++)
			MATDproduit = MATDproduit * pMATDbdd[uiBoucleBdd]; //de gauche a droite
		cout << " = \n\n";
		MATDproduit.MATprint(0);
	}
	catch (CException EXCsommeM) {
		cout << endl;
		EXCsommeM.EXCGestionaireException();
	}
	

	delete[] pMATDbdd;
	return 0;
}
