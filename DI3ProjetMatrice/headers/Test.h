#define TESTH
#ifndef DI3PROJETMATRICEH
#include "../headers/DI3ProjetMatrice.h"
#endif

template<class T, class T2>
int CMatriceTest() {
	try {
		//constructeur (uiArgX,uiArgY,Targ) potentielle conversion de 1.1 (double) en T
		CMatrice<T> MAT = CMatrice<T>(5, 5, 1.1);

		//instanciation implicite de CMatrice<T2>, constructeur (uiArgX,uiArgY,T2arg) potentielle conversion de 2.2 (double) en T2
		CMatrice<T2> MAT2 = CMatrice<T2>(5, 5, 2.2);
		
		//operateur= et potentielle conversion via operateur MAT() de MAT2
		MAT = MAT2;
		
		//potentielle conversion de -1234567891012131415 (long long) en T
		MAT.MATsetElem(2, 2, -1234567891012131415 );

		//insertion d'un element unitaire de T (a condition que l'operateur ! soit defini)
		MAT.MATsetElem(0, 0, !T()); //T() est le constructeur par defaut de T

		//insertion d'un element nul de T
		MAT.MATsetElem(4, 4, T()); //T() est le constructeur par defaut de T

		//generation d'une erreur de dimensions incompatibles
		MAT.MATsetElem(5, 5, 0);

		MAT.MATprint(1);
	}
	catch (CException EXClevee) {
		EXClevee.EXCGestionaireException();
		std::cout << "\n\n";
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
