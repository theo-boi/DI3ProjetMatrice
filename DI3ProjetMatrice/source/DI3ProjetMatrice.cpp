#include "../headers/DI3ProjetMatrice.h"

int main()
{
	//init
	CMatriceDouble* pMAD1 = new CMatriceDouble();
	CMatriceDouble* pMAD2 = new CMatriceDouble(2, 2);

	//corps
	pMAD1->MATPrint(); //postcondition : neant
	pMAD2->MATPrint(); //postcondition : {0 0}^2
	std::cout << std::endl;

	//delete
	delete pMAD1;
	delete pMAD2;
	return 0;
}
