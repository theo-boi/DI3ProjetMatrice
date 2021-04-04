#define CFICHIERH 0
#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif

#include <iostream>

class CFichier {

    //attributs
    private :
        char pcFICnom;
        FILE* pFICfichier;
        CMatriceDouble pMADmatrice;
};