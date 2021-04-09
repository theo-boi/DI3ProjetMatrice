#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main()
{
	//tests CMatrice
	//CMatriceTestGlobal();
	
	//tests CFichier
	printf("TESTS FICHIER\n");
	CFichier fichier("fichierMatrice.txt");
	CFichier fichier1(fichier);
	CFichier fichier2 = fichier1;
	CMatrice<double> MATD = fichier2.FICgetCMatrice();
	fichier2.FICprintCMatrice();

	return 0;
}
