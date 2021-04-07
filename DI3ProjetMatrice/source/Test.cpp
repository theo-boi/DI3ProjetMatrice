#include "../headers/Test.h"
using namespace std;

/* Tests */

int CMatriceDoubleTestPrint(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg\n\n";
	try {
		MADArg.MATPrint(1);
	}
	catch (CException EXCLevee) {
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
	}
	return 0;
}

int CMatriceDoubleTestMult(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg x MADArg^t\n\n\n";
	try {
		CMatriceDouble MADArgT = MADArg.MADt();
		(MADArg * MADArgT).MATPrint();
	}
	catch (CException EXCLevee) {
		if (EXCLevee.EXCGestionaireException())
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
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
		
		MAD1*MAD2; //type d'exception 2 // arrete l'execution du bloc et leve l'execution du bloc B
		
	}
	catch (CException EXCLevee) {
		if (EXCLevee.EXCGestionaireException()) {
			cout << "On a arrete l'execution du bloc.\n";
			//on admet qu'on ne sait pas quoi faire et on arrete brusquement le programme
			throw(EXCLevee);
		}
	}
	cout << "L'execution du programme continue !\n\n\n";
	return 0;
}
