#include "../headers/DI3ProjetMatrice.h"
using namespace std;

int main()
{
	//test
	CMatriceTestGlobal();
	
	//tests fichiers
	printf("TESTS FICHIER\n");
	CFichier fichier("fichierMatrice.txt");
	CFichier fichier1(fichier);
	CFichier fichier2 = fichier1;
	CMatrice<double> MATD = fichier2.FICgetMatrice();
	fichier2.FICafficherMatrice();

	return 0;
}
