#define TESTH
#ifndef DI3PROJETMATRICEH
#include "../headers/DI3ProjetMatrice.h"
#endif

template <class T>
int CMatriceTest() {
	std::cout << "Afficher MATint\n\n";
	try {
		CMatrice<T> MAD0 = CMatrice<double>(5, 5); //instanciation implicite de template : delcaration+definition de la classe CMatrice<int>
		MAD0.MATprint();
	}
	catch (CException EXCLevee) {
		EXCLevee.EXCGestionaireException();
	}
	return 0;
};

int CMatriceDoubleConstTest();

int CMatriceDoubleTestPrint(CMatriceDouble& MADArg);

int CMatriceDoubleTestMultConst(CMatriceDouble& MADArg);

int CMatriceDoubleTestDivConst(CMatriceDouble& MADArg);

int CMatriceDoubleTestT(CMatriceDouble& MADArg);

int CMatriceDoubleTestAdd(CMatriceDouble& MADArg);

int CMatriceDoubleTestSous(CMatriceDouble& MADArg);

int CMatriceDoubleTestMult(CMatriceDouble& MADArg);

int CExceptionTest();
