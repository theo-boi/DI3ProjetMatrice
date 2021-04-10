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
	const unsigned int uiNbFichiers = argc - 1;
	CMatrice<double>* pMATDbdd = new CMatrice<double>[uiNbFichiers]; //matrices extraites des fichiers

	//extraction des matrices des fichiers entres en arguments du fichier executable
	for (unsigned int uiBoucleArgs = 0; uiBoucleArgs < uiNbFichiers; uiBoucleArgs++) {
		cout << argv[uiBoucleArgs + 1];
		CFichier fichier( argv[uiBoucleArgs+1] );
		pMATDbdd[uiBoucleArgs] = fichier.FICgetCMatrice();
	}

	//affichage des matrices
	for (unsigned int uiBoucleBdd = 0; uiBoucleBdd < uiNbFichiers; uiBoucleBdd++) {
		cout << "Matrice du fichier " << uiBoucleBdd << endl;
		pMATDbdd->MATprint(1);
	}
	/*
	double dConstante;
	cout << "Constante c = "; cin >> dConstante;
	cout << dConstante;
	*/
	delete[] pMATDbdd;
	return 0;
}
