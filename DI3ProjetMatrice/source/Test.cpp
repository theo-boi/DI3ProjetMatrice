#include "../headers/Test.h"
using namespace std;

/* Tests */

int CMatriceDoubleConstTest() {
	const CMatriceDouble* pMAD1 = new CMatriceDouble(2, 2); //MAD1 = ((1,1), (1,1))

	/*
	 *	Teste la compatibilite des fonctions avec les objets constants
	 */
	try {
		cout << "Afficher MADConstante\n\n";
		pMAD1->MATPrint(1);
		*pMAD1 * 10; //MADArg*10
		10 * *pMAD1; //10*MADArg
		*pMAD1 / 10; //MADArg/10
		pMAD1->MADt();
		*pMAD1 + 10 * CMatriceDouble(pMAD1->MATGetDimLigne(), pMAD1->MATGetDimColonne());
		*pMAD1 - 10 * CMatriceDouble(pMAD1->MATGetDimLigne(), pMAD1->MATGetDimColonne());
		pMAD1->MADGetElem((double)0, (double)0);
		*pMAD1 * pMAD1->MADt();
		//*pMAD1->MADSetElem(0, 0, 0); //ne fonctionne pas car MADSetElem ne peut pas etre une methode constante
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceDoubleTestPrint(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg\n\n";
	try {
		MADArg.MATPrint(1);
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceDoubleTestMultConst(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg*10 et 10*MADArg\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise MADArg.operator*(10)
	 */
	try {
		( MADArg * 10 ).MATPrint(1); //MADArg*10
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	cout << endl;
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise operator*(10, MADArg)
	 *	car 10.operator*(MADArg) n'est pas surchargeable
	 */
	try {
		( 10 * MADArg ).MATPrint(1); //10*MADArg
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceDoubleTestDivConst(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg/10 (10/MADArg n'est pas demande)\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise MADArg.operator/(10)
	 */
	try {
		(MADArg / 10).MATPrint(1); //MADArg/21
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}

	/*
	 *	10/MADArg = 10*MADArg^(-1), donc il faudrait coder une methode pour inverser MADArg
	 *	or, ni cette operation ni cette methode  ne sont demandees dans les specifications
	 */
	return 0;
}

int CMatriceDoubleTestT(CMatriceDouble& MADArg) {
	cout << "Afficher la transposee de MADArg\n\n\n";
	try {
		MADArg.MADt().MATPrint(1);
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceDoubleTestAdd(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg + [10 10 10 ... 10]x[10 10 10 ... 10]\n\n\n";
	CMatriceDouble MADDix = CMatriceDouble(MADArg.MATGetDimLigne(), MADArg.MATGetDimColonne());
	try {
		(MADArg + (10 * MADDix)).MATPrint();
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceDoubleTestSous(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg - [10 10 10 ... 10]x[10 10 10 ... 10]\n\n\n";
	try {
		CMatriceDouble MADDix = 10 * CMatriceDouble(MADArg.MATGetDimLigne(), MADArg.MATGetDimColonne());
		(MADArg - MADDix).MATPrint();
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CMatriceDoubleTestMult(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg * MADArg^t\n\n\n";
	try {
		CMatriceDouble MADArgT = MADArg.MADt();
		(MADArg * MADArgT).MATPrint();
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
}

int CExceptionTest() {
	CMatriceDouble MAD1 = CMatriceDouble(2, 2);
	CMatriceDouble MAD2 = CMatriceDouble(3, 3);

	try {
		
		CException A;
		A.EXCSetId(types_incompatibles); //type d'exception 1
		//A.EXCSetId(0); //type d'exception inconnu
		A.EXCSetCommentaire("blablabla");
		throw(A); //arrete l'execution du bloc et leve l'exception A
		
		MAD1*MAD2; //type d'exception 2 // arrete l'execution du bloc et leve l'execution B
		
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException(); //si EXCLevee est inconnue, throw(EXCLevee) au niveau superieur
	}
	cout << "L'execution du programme continue !\n\n\n";
	return 0;
}
