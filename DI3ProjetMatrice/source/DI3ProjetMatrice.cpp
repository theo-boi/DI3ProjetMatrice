#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main()
{
	//init
	
	const CMatrice<double>* pMAT1 = new CMatrice<double>(2,2, 1); //MAT1 = ((1,1), (1,1))

	CMatrice<double>* pMAT2 = new CMatrice<double>(2, 2); //MAT2 = I_2
	pMAT2->MATsetElem(0, 1, 0);
	pMAT2->MATsetElem(1, 0, 0);

	CMatrice<double> MAT3 = CMatrice<double>(3, 4); //MAT3 = ((1,4,1), (2,5,1), (3,6,1), (1,1,1))
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
	CMatriceTest<int,double>(); //MAT
	std::cout << "Afficher MATbool\n\n";
	CMatriceTest<bool,float>(); //MAT
	std::cout << "Afficher MATdouble\n\n";
	CMatriceTest<double,int>(); //MAT
	cout << "---------\n\n\n---------\n\n\n";

	//delete
	delete pMAT1;
	delete pMAT2;
	
	//tests fichiers
	printf("TESTS FICHIER\n");
	CFichier fichier("fichierMatrice.txt");
	CFichier fichier1(fichier);
	CFichier fichier2 = fichier1;
	CMatrice<double> MATD = fichier2.FICgetMatrice();
	fichier2.FICafficherMatrice();

	return 0;
}
