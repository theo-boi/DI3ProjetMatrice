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
		case 3:
			cout << " \"division par zero\"";
			break;
		default:
			cout << " inconnue";
			bInconnue = true;
			break;
	}
	if (EXCGetCommentaire()) cout << " dans " << EXCGetCommentaire();
	cout << "\n";

	if (bInconnue) throw(this);
}
