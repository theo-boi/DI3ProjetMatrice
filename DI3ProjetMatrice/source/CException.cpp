#ifndef CEXCEPTIONH
#include "../headers/CException.h"
#endif
using namespace std;

void CException::EXCSetCommentaire(const char* pccArg) {
	unsigned int uiBoucleWhile;
	for (uiBoucleWhile = 0; pccArg[uiBoucleWhile] && uiBoucleWhile < 79; uiBoucleWhile++)
		pcEXCCommentaire[uiBoucleWhile] = pccArg[uiBoucleWhile];
	pcEXCCommentaire[uiBoucleWhile] = '\0';
}

bool CException::EXCGestionaireException(CException EXCLevee) {
	bool bInconnue = false;
	bool bDanger = false;
	cout << "Erreur";

	switch (EXCLevee.EXCGetId()) {
		case 1:
			cout << " \"types incompatibles\"";
			bDanger = true;
			break;
		case 2:
			cout << " \"dimensions incompatibles\"";
			bDanger = true;
			break;
		default:
			bInconnue = true;
			cout << " inconnue";
	}

	if (EXCLevee.EXCGetCommentaire()) cout << " : " << EXCLevee.EXCGetCommentaire();
	cout << "\n";

	return bInconnue || bDanger;
}
