#define TESTH
#ifndef DI3PROJETMATRICEH
#include "../headers/DI3ProjetMatrice.h"
#endif

template <class T>
int CMatriceTest() {
	std::cout << "Afficher MAT\n\n";
	try {
		CMatrice<T> MAD0;
		CMatrice<double>* pMAD1 = new CMatrice<double>(5, 5, 1.1); //instanciation implicite de template : delcaration + definition de la classe CMatrice<int>
		MAD0 = *pMAD1;
		MAD0.MATsetElem(2, 2, -1234567891012131415 );
		MAD0.MATprint(1);
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
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
