#define CFICHIERH 0
#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif

#include <iostream>

class CFichier {

    //attributs
    private :
        const char* pcFICnom;
        FILE* pFICfichier;
        CMatriceDouble* pMADmatrice;

    //constructeur et destructeur
    public :
        CFichier();
		CFichier(const char* pcFICnomFichier);
        ~CFichier();

        //fonction principale
        /*
		 *	Methode sans arguments permettant de lire le contenu d'une matrice double dans un fichier formaté et de créer une matrice en mémoire à partie des données lues
		 *
		 *	Entree : rien
		 *	Precondition : pcFICnom et pFICfichier ne sont pas null
		 *	Sortie : rien
		 *	Postcondition : les données de la matrice pMADmatrice correspondent à celles du fichier pFICfichier
		 */
        void FICprincipale();
};