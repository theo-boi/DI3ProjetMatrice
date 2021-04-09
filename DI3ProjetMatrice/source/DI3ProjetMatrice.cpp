#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main()
{
	//init
	
	const CMatriceDouble* pMAD1 = new CMatriceDouble(2,2); //MAD1 = ((1,1), (1,1))
	const CMatriceDouble MAD1CopieStatique = *pMAD1;

	CMatriceDouble* pMAD2 = new CMatriceDouble(2, 2); //MAD2 = I_2
	pMAD2->MADSetElem(0, 1, 0);
	pMAD2->MADSetElem(1, 0, 0);

	CMatriceDouble* pMAD3 = new CMatriceDouble(3, 4); //MAD3 = ((1,4,1), (2,5,1), (3,6,1), (1,1,1))
	pMAD3->MADSetElem(0, 1, 2);
	pMAD3->MADSetElem(0, 2, 3);
	pMAD3->MADSetElem(1, 0, 4);
	pMAD3->MADSetElem(1, 1, 5);
	pMAD3->MADSetElem(1, 2, 6);

	*pMAD2 = MAD1CopieStatique * MAD1CopieStatique;
	CMatriceDouble* pMADArg = pMAD3;
	
	//tests
	CMatriceDoubleConstTest();
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
	cout << "---------\n\n\n---------\n\n\n";

	CExceptionTest();
	cout << "---------\n\n\n---------\n\n\n";


	std::cout << "Afficher MATint\n\n";
	CMatriceTest<int,double>(); //MAT
	std::cout << "Afficher MATbool\n\n";
	CMatriceTest<bool,float>(); //MAT
	std::cout << "Afficher MATdouble\n\n";
	CMatriceTest<double,int>(); //MAT
	cout << "---------\n\n\n---------\n\n\n";


	//delete
	delete pMAD1;
	delete pMAD2;
	delete pMAD3;
	
	//tests fichiers
	printf("TESTS FICHIER\n");
	CFichier fichier("fichierMatrice.txt");
	CFichier fichier1(fichier);
	CFichier fichier2 = fichier1;
	CMatrice<double> MATD = fichier2.FICgetMatrice();
	fichier2.FICafficherMatrice();

	return 0;
}
