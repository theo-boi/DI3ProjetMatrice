#define CFICHIERH 0
#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif

#include <iostream>

class CFichier {

    //attributs
    private :
        char* pcFICnom;
        FILE* pFICfichier;
        CMatriceDouble* pMADmatrice;

    //constructeur et destructeur
    public :
        CFichier();
        ~CFichier();

        //fonction principale
        /*
		 *	Methode prenant en argument le nom d'un fichier texte (formaté) permettant d'en lire le contenu d'une matrice double et de créer une matrice en mémoire à partie des données lues
		 *
		 *	Entree : rien
		 *	Precondition : pcFICnom et pFICfichier ne sont pas null
		 *	Sortie : rien
		 *	Postcondition : les données de la matrice pMADmatrice correspondent à celles du fichier pFICfichier
		 */
        void FICprincipale(const char* pcNomFichier);
};