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

	//tests
	CMatriceDoubleTestPrint(*pMAD1);
	CMatriceDoubleTestPrint(*pMAD2);
	cout << "---------\n\n\n";

	CMatriceDoubleTestMultConst(*pMAD1);
	CMatriceDoubleTestMultConst(*pMAD2);
	cout << "---------\n\n\n";

	//delete
	delete pMAD1;
	delete pMAD2;
	return 0;

	//tests fichiers
	//CMatriceDouble MAD FICprincipale("../fichierMatrice.txt");
}
