#ifndef TESTH
#include "../headers/Test.h"
#endif
using namespace std;

int CFichierTest() {
	printf("TESTS FICHIER\n");
	CFichier fichier("fichierMatrice.txt");
	CFichier fichier1(fichier); //utilise constructeur de recopie, meme signification pour le compilateur que la ligne suivante
	CFichier fichier2 = fichier1; //utilise constructeur de recopie (car pendant une initialisation)
	fichier2 = fichier1; //utilise operator=, signification differente pour le compilateur que la ligne precedente
	CMatrice<double> MATD = fichier.FICgetCMatrice();
	fichier.FICprintCMatrice();
	return 0;
}

int CMatriceTestGlobal() {
	//init
	const CMatrice<double>* pMAT1 = new CMatrice<double>(2, 2, 1); //*pMAT1 = ((1,1), (1,1))

	CMatrice<double>* pMAT2 = new CMatrice<double>(2, 2); //*pMAT2 = I_2
	pMAT2->MATsetElem(1, 0, 1);
	pMAT2->MATsetElem(0, 1, 1);

	CMatrice<double> MAT3 = CMatrice<double>(3, 4); //MAT3 = ((1,4,0), (2,5,0), (3,6,0), (1,1,0))
	MAT3.MATsetElem(0, 0, 1);
	MAT3.MATsetElem(0, 1, 2);
	MAT3.MATsetElem(0, 2, 3);
	MAT3.MATsetElem(1, 0, 4);
	MAT3.MATsetElem(1, 1, 5);
	MAT3.MATsetElem(1, 2, 6);

	//tests
	CMatriceTestConst(pMAT1);
	cout << "---------\n\n\n---------\n\n\n";

	CMatriceTestPrint(MAT3); //MAT
	cout << "---------\n\n\n";

	CMatriceTestMultConst(MAT3); //MAT*10 et 10*MAT
	cout << "---------\n\n\n";

	CMatriceTestDivConst(MAT3); //MAT/10 et 10/MAT
	cout << "---------\n\n\n";

	CMatriceTestT(MAT3); //MAT^T
	cout << "---------\n\n\n";

	CMatriceTestAdd(MAT3); //MAT + (MAT*10)
	cout << "---------\n\n\n";

	CMatriceTestSous(MAT3); //MAT1 - (MAT*10)
	cout << "---------\n\n\n";

	CMatriceTestMult(MAT3); //MAT * MAT
	cout << "---------\n\n\n---------\n\n\n";

	CExceptionTest();
	cout << "---------\n\n\n---------\n\n\n";

	std::cout << "Afficher MATint\n\n";
	CMatriceTest<int, double>(); //MAT
	std::cout << "Afficher MATbool\n\n";
	CMatriceTest<bool, float>(); //MAT
	std::cout << "Afficher MATdouble\n\n";
	CMatriceTest<double, int>(); //MAT
	cout << "---------\n\n\n---------\n\n\n";

	//delete
	delete pMAT1;
	delete pMAT2;
	return 0;
}


/* Tests */

int CMatriceTestConst(const CMatrice<double>* pMATConst) {
	//init
	const CMatrice<double> MATConst = *pMATConst; //MAT1 = ((1,1), (1,1))

	//teste la compatibilite des fonctions avec les objets constants
	cout << "Afficher MATConstante\n\n";
	try {
		MATConst.MATprint(1);
		MATConst * 10; //MATArg*10
		10 * MATConst; //10*MATArg
		MATConst / 10; //MATArg/10
		MATConst.MATt();
		MATConst + 10 * CMatrice<double>(MATConst.MATgetDimLigne(), MATConst.MATgetDimColonne());
		MATConst - 10 * CMatrice<double>(MATConst.MATgetDimLigne(), MATConst.MATgetDimColonne());
		MATConst.MATgetElem((double)0, (double)0);
		MATConst * MATConst.MATt();
		//MATConst = MATConst * MATConst; //ne fonctionne pas car operator= ne peut pas etre une methode constante
		//*MATConst.MATSetElem(0, 0, 0); //ne fonctionne pas car MATSetElem ne peut pas etre une methode constante
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}

	return 0;
}

int CMatriceTestPrint(CMatrice<double>& MATArg) {
	cout << "Afficher MATArg\n\n";
	try {
		MATArg.MATprint(1);
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceTestMultConst(CMatrice<double>& MATArg) {
	cout << "Afficher MATArg*10 et 10*MATArg\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatrice<double> temporaire
	 *	Le compilateur utilise MATArg.operator*(10)
	 */
	try {
		( MATArg * 10 ).MATprint(1); //MATArg*10
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	cout << endl;
	/*
	 *	Calcul puis affichage de l'objet CMatrice<double> temporaire
	 *	Le compilateur utilise operator*(10, MATArg)
	 *	car 10.operator*(MATArg) n'est pas surchargeable
	 */
	try {
		( 10 * MATArg ).MATprint(1); //10*MATArg
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceTestDivConst(CMatrice<double>& MATArg) {
	cout << "Afficher MATArg/10 (10/MATArg n'est pas demande)\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatrice<double> temporaire
	 *	Le compilateur utilise MATArg.operator/(10)
	 */
	try {
		(MATArg / 10).MATprint(1); //MATArg/21
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}

	/*
	 *	10/MATArg = 10*MATArg^(-1), donc il faudrait coder une methode pour inverser MATArg
	 *	or, ni cette operation ni cette methode  ne sont demandees dans les specifications
	 */
	return 0;
}

int CMatriceTestT(CMatrice<double>& MATArg) {
	cout << "Afficher la transposee de MATArg\n\n\n";
	try {
		MATArg.MATt().MATprint(1);
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceTestAdd(CMatrice<double>& MATArg) {
	cout << "Afficher MATArg + [10 10 10 ... 10]x[10 10 10 ... 10]\n\n\n";
	CMatrice<double> MATDix = CMatrice<double>(MATArg.MATgetDimLigne(), MATArg.MATgetDimColonne(), 1);
	try {
		(MATArg + (10 * MATDix)).MATprint();
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceTestSous(CMatrice<double>& MATArg) {
	cout << "Afficher MATArg - [10 10 10 ... 10]x[10 10 10 ... 10]\n\n\n";
	try {
		CMatrice<double> MATDix = 10 * CMatrice<double>(MATArg.MATgetDimLigne(), MATArg.MATgetDimColonne(), 1);
		(MATArg - MATDix).MATprint();
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceTestMult(CMatrice<double>& MATArg) {
	cout << "Afficher MATArg * MATArg^t\n\n\n";
	try {
		CMatrice<double> MATArgT = MATArg.MATt();
		(MATArg * MATArgT).MATprint();
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
	}
	return 0;
}

int CExceptionTest() {
	//init
	CMatrice<double> MAT1 = CMatrice<double>(2, 2);
	CMatrice<double> MAT2 = CMatrice<double>(3, 3);

	//test
	try {
		
		CException A;
		A.EXCSetId((int) "mystere"); //type d'exception inconnu
		A.EXCSetCommentaire("CExceptionTest() : test");
		//throw(A); //arrete l'execution du bloc et leve l'exception A
		
		MAT1*MAT2; //type d'exception 2 // arrete l'execution du bloc et leve l'execution B
		
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException(); //si EXClevee est inconnue, throw(EXClevee) au niveau superieur. Ici : arrete le programme
	}
	cout << "L'execution du programme continue !\n\n\n";
	return 0;
}
