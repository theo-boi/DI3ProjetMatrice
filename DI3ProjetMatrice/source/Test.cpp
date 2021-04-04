#include "../headers/Test.h"
using namespace std;

/*
 *	Attention developpeurs : creer une classe capable de regrouper ce type d'operateur de type de base
 *	Pour l'instant defini dans Test.cpp
 */
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

/* Tests */

int CMatriceDoubleTestPrint(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg\n\n";
	MADArg.MATPrint(1);
	return 0;
}

int CMatriceDoubleTestMultConst(CMatriceDouble& MADArg) {
	cout << "Afficher MADArg*21 et 21*MADArg\n\n\n";
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur comprend MADArg.operator*(21)
	 */
	( MADArg * 21 ).MATPrint(1); //MADArg*21

	cout << endl;
	/*
	 *	Calcul puis affichage de l'objet CMatriceDouble temporaire
	 *	Le compilateur utilise operator*(21, MADArg)
	 *	car 21.operator*(MADArg) n'est pas surchargeable
	 */
	( 21 * MADArg ).MATPrint(1); //21*MADArg
	return 0;
}
