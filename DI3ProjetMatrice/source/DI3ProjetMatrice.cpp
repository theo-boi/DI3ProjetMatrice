#include "../headers/DI3ProjetMatrice.h"
using namespace std;


/*
 *	Attention developpeurs : creer une classe capable de regrouper ce type d'operateur de type de base
 *	Pour l'instant defini dans Test.cpp
 */
/*
CMatriceDouble& operator*(const long double cldArg, const CMatriceDouble MADArg) {
	//init
	CMatriceDouble* pMADMult = new CMatriceDouble(MADArg);

	for (unsigned int uiBoucleForX = 0; uiBoucleForX < pMADMult->MATGetDimLigne(); uiBoucleForX++) {
		//calcul de chaque element par vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < pMADMult->MATGetDimColonne(); uiBoucleForY++) {
			pMADMult->MADSetElem(uiBoucleForX, uiBoucleForY, pMADMult->MADGetElem(uiBoucleForX, uiBoucleForY)*cldArg);
		}
	}

	return *pMADMult;
}
*/

int main()
{
	//init
	CMatriceDouble* pMAD1 = new CMatriceDouble(2,2); //MAD1 = ((1,1), (1,1))
	
	CMatriceDouble* pMAD2 = new CMatriceDouble(2, 2); //MAD2 = I_2
	pMAD2->MADSetElem(0, 1, 0);
	pMAD2->MADSetElem(1, 0, 0);

	CMatriceDouble* pMAD3 = new CMatriceDouble(3, 4); //MAD3 = ((1,4,1), (2,5,1), (3,6,1), (1,1,1))
	pMAD3->MADSetElem(0, 1, 2);
	pMAD3->MADSetElem(0, 2, 3);
	pMAD3->MADSetElem(1, 0, 4);
	pMAD3->MADSetElem(1, 1, 5);
	pMAD3->MADSetElem(1, 2, 6);

	//tests
	CMatriceDoubleTestPrint(*pMAD3);
	CMatriceDoubleTestMultConst(*pMAD3);
	cout << "---------\n\n\n";

	CMatriceDoubleTestDivConst(*pMAD3);
	cout << "---------\n\n\n";
	
	CMatriceDoubleTestT(*pMAD3);
	cout << "---------\n\n\n";

	CMatriceDoubleTestAdd(*pMAD3); //*pMAD1 + (*pMAD1*10)
	cout << "---------\n\n\n";

	CMatriceDoubleTestSous(*pMAD3);
	cout << "---------\n\n\n";

	CMatriceDoubleTestMult(*pMAD3);
	cout << "---------\n\n\n";

	//delete
	delete pMAD1;
	delete pMAD2;
	delete pMAD3;
	return 0;

	//tests fichiers
	//CMatriceDouble MAD FICprincipale("../fichierMatrice.txt");
}
