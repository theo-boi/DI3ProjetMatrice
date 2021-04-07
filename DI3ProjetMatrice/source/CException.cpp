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

bool CException::EXCGestionaireException() const {
	bool bInconnue = false;
	bool bDanger = false;
	cout << "Erreur";

	switch (EXCGetId()) {
		case 1:
			cout << " \"types incompatibles\"";
			break;
		case 2:
			cout << " \"dimensions incompatibles\"";
			break;
		default:
			bInconnue = true;
			cout << " inconnue";
			break;
	}

	if (EXCGetCommentaire()) cout << " : " << EXCGetCommentaire();
	cout << "\n";

	return (bInconnue || bDanger);
}
