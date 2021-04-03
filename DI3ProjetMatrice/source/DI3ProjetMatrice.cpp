#include "../headers/DI3ProjetMatrice.h"
using namespace std;

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

int main()
{
	//init
	CMatriceDouble* pMAD1 = new CMatriceDouble(2,2); //MAD1 = ((1,1), (1,1))
	pMAD1->MADSetElem(0, 0, 1);
	pMAD1->MADSetElem(0, 1, 1);
	pMAD1->MADSetElem(1, 0, 1);
	pMAD1->MADSetElem(1, 1, 1);
	CMatriceDouble* pMAD2 = new CMatriceDouble(2, 2); //MAD2 = I_2
	pMAD2->MADSetElem(0, 0, 1);
	pMAD2->MADSetElem(0, 1, 0);
	pMAD2->MADSetElem(1, 0, 0);
	pMAD2->MADSetElem(1, 1, 1);

	//calculs
	cout << "1. Afficher MAD1 et MAD2\n\n\n";
	pMAD1->MATPrint(1);
	cout << endl;
	pMAD2->MATPrint(1);
	cout << "---------\n\n\n";

	cout << "2. 1. MAD1*21 et 21*MAD1\n\n\n";
	( *pMAD1 * 21 ).MATPrint(1); //MAD1*21
	cout << endl;
	( 21 * (*pMAD1) ).MATPrint(1); //21*MAD1
	cout << "---------\n\n\n";

	cout << "2. 2. MAD2*22 et 22*MAD2\n\n\n";
	( *pMAD2 * 22 ).MATPrint(1); //MAD2*22
	cout << endl;
	( 22 * (*pMAD2) ).MATPrint(1); //22*MAD2
	cout << "---------\n\n\n";
	

	//delete
	delete pMAD1;
	delete pMAD2;
	return 0;
}
