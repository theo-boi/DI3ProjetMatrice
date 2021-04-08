#define CFICHIERH
#ifndef CMATRICEDOUBLEH
#include "../headers/CMatriceDouble.h"
#endif
#include <iostream>

class CFichier {

    //ATTRIBUTS
    private :
        char* pcFICnom; //un pointeur sur le premier caractère le nom du fichier
        FILE* pFICfichier; //un pointeur placé au début du fichier
        CMatriceDouble* pMADmatrice; //un pointeur sur un objet CMatriceDouble

    //CONSTRUCTEURS ET DESTRUCTEUR
    public :

		/*
		 *	Constructeur par defaut permettant d'initialiser un CFichier
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : FICNew : un objet CFichier
		 *	Postcondition : Les attributs de l'objet CFichier sont alloues/initialises
		 */
        CFichier();

		/*
		 *	Constructeur de recopie
		 *
		 *	Entree : FICarg : CFichier
		 *	Precondition : FICarg existe et est alloue
		 *	Sortie : FICNew : un objet CFichier
		 *	Postcondition : Les attributs de l'objet FICNew sont alloues/initialises et possèdent la même valeur que ceux de FICarg
		 */
		CFichier(CFichier &FICarg);

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Les attributs de l'objet CFichier sont liberes
		 */
        ~CFichier();

        //FONCTION PRINCIPALE
        /*
		 *	Methode prenant en argument le nom d'un fichier texte (formaté) permettant d'en lire le contenu d'une matrice double et de créer une matrice en mémoire à partie des données lues
		 *
		 *	Entree : rien
		 *	Precondition : pcFICnom et pFICfichier ne sont pas null
		 *	Sortie : rien
		 *	Postcondition : les données de la matrice pMADmatrice correspondent à celles du fichier pFICfichier
		 */
        void FICprincipale(const char* pcNomFichier);

		//OPERATEURS
		/*
		 *	Methode de type operateur a un argument recopiant le CFichier FICarg
		 *
		 *	Entree : FICarg : CFichier
		 *	Precondition : neant
		 *	Sortie : FICEgal : CFichier
		 *	Postcondition : {FICEgal = FICarg}
		 */
		CFichier& operator=(CFichier &FICarg);
	
};