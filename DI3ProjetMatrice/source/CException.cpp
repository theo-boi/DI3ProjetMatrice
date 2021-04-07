#ifndef CEXCEPTIONH
#include "../headers/CException.h"
#endif
using namespace std;

void CException::EXCGestionaireException() const throw(CException) {
	bool bInconnue = false;

	cout << "Erreur";
	switch (EXCGetId()) {
		case 1:
			cout << " \"types incompatibles\"";
			break;
		case 2:
			cout << " \"dimensions incompatibles\"";
			break;
		default:
			cout << " inconnue";
			bInconnue = true;
			break;
	}
	if (EXCGetCommentaire()) cout << " : " << EXCGetCommentaire();
	cout << "\n";

	if (bInconnue) throw(this);
}
