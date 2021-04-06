#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main()
{
	//init
	const CMatriceDouble* pMAD1 = new CMatriceDouble(2,2); //MAD1 = ((1,1), (1,1))
	CMatriceDouble MAD1Copie = *pMAD1;

	CMatriceDouble* pMAD2 = new CMatriceDouble(2, 2); //MAD2 = I_2
	pMAD2->MADSetElem(0, 1, 0);
	pMAD2->MADSetElem(1, 0, 0);

	CMatriceDouble* pMAD3 = new CMatriceDouble(3, 4); //MAD3 = ((1,4,1), (2,5,1), (3,6,1), (1,1,1))
	pMAD3->MADSetElem(0, 1, 2);
	pMAD3->MADSetElem(0, 2, 3);
	pMAD3->MADSetElem(1, 0, 4);
	pMAD3->MADSetElem(1, 1, 5);
	pMAD3->MADSetElem(1, 2, 6);

	CMatriceDouble* pMADArg = pMAD3;
	
	//tests
	/*
	 *	Teste la compatibilite avec les objets constants
	 */
	cout << "Afficher MADConstante\n\n";
	pMAD1->MATPrint(1);
	*pMAD1 * 10; //MADArg*10
	10 * *pMAD1; //10*MADArg
	*pMAD1 / 10; //MADArg/10
	pMAD1->MADt();
	*pMAD1 + 10*CMatriceDouble(pMAD1->MATGetDimLigne(), pMAD1->MATGetDimColonne());
	*pMAD1 - 10*CMatriceDouble(pMAD1->MATGetDimLigne(), pMAD1->MATGetDimColonne());
	pMAD1->MADGetElem((double)0, (double)0);
	*pMAD1 * pMAD1->MADt();
	//*pMAD1->MADSetElem(0, 0, 0); //ne fonctionne pas car MADSetElem ne peut pas etre une methode constante
	cout << "---------\n\n\n---------\n\n\n";
	
	CMatriceDoubleTestPrint(*pMADArg); //MAD
	cout << "---------\n\n\n";

	CMatriceDoubleTestMultConst(*pMADArg); //MAD*10 et 10*MAD
	cout << "---------\n\n\n";

	CMatriceDoubleTestDivConst(*pMADArg); //MAD/10 et 10/MAD
	cout << "---------\n\n\n";
	
	CMatriceDoubleTestT(*pMADArg); //MAD^T
	cout << "---------\n\n\n";

	CMatriceDoubleTestAdd(*pMADArg); //MAD + (MAD*10)
	cout << "---------\n\n\n";

	CMatriceDoubleTestSous(*pMADArg); //MAD1 - (MAD*10)
	cout << "---------\n\n\n";

	CMatriceDoubleTestMult(*pMADArg); //MAD * MAD
	cout << "---------\n\n\n";

	CExceptionTest();

	//delete
	delete pMAD1;
	delete pMAD2;
	delete pMAD3;

	//tests fichiers
	CFichier fichier("fichierMatrice.txt");
	printf("TESTS FICHIER\n");
	//fichier.FICprincipale();

	return 0;
}
