#define CFICHIERH

#ifndef CMATRICEH
#include "CMatrice.h"
#endif

#include <iostream>

class CFichier {

    //ATTRIBUTS
    private :
        const char* pcFICnom; //un pointeur sur le premier caractère le nom du fichier
        FILE* pFICfichier; //un pointeur placé au début du fichier
        CMatrice<double>* pMATDmatrice; //un pointeur sur un objet CMatriceDouble

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
		 *	Constructeur prenant en argument le nom d'un fichier
		 *
		 *	Entree : pcNomFichier : char*
		 *	Precondition : pcNomFichier existe
		 *	Sortie : FICNew : un objet CFichier
		 *	Postcondition : Les attributs de l'objet FICNew sont alloues/initialises à partir du fichier concerné
		 */
		CFichier(const char* pcNomFichier);

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Les attributs de l'objet CFichier sont liberes
		 */
        ~CFichier();


	//ACCESSEURS
		//EN ECRITURE
		/*
		 *	Methode de type accesseur prenant en argument un pointeur sur une chaine de caractère pcNomFichier
		 *
		 *	Entree : pcNomFichier : char*
		 *	Precondition : pcNomFichier existe
		 *	Sortie : Rien
		 *	Postcondition : {pcFICnom = pcNomFichier}
		 */
		void FICsetNomFichier(const char* pcNomFichier);

		//EN LECTURE

		/*
		 *	Methode de type accesseur sans argument permettant de récupérer l'objet pcFICnom et de le stocker en mémoire
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : pcNew : char*
		 *	Postcondition : {pcNew = pcFICnom}
		 */
		const char* FICgetNomFichier();

		/*
		 *	Methode de type accesseur sans argument permettant de récupérer l'objet pMATDmatrice et de le stocker en mémoire
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MATDnew : CMatrice<double>
		 *	Postcondition : {MATDnew = *pMATDmatrice}
		 */
		CMatrice<double> FICgetMatrice();

		/*
		 *	Methode de type accesseur a deux arguments renvoyant l'element de pMATDmatrice de coordonnees (uiX, uiY)
		 *	Remarques :
		 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiX : entier non signe, uiY : entier non signe
		 *	Precondition : (uiX < CFichier.pMATDmatrice.eMATdimLigne)^(uiY < CFichier.pMATDmatrice.eMATdimLigne)
		 *	Sortie : dElem : double
		 *	Postcondition : {dElem = CFichier.pMATDmatrice.ppdMATElem[uiX][uiY]}
		 */
		double FICgetMatriceElement(const unsigned int uiX, const unsigned int uiY);


	//FONCTION PRINCIPALE
        /*
		 *	Methode permettant de lire le contenu d'une matrice double dans un fichier texte et de créer une matrice en mémoire à partie des données lues
		 *
		 *	Entree : rien
		 *	Precondition : pcFICnom et pFICfichier ne sont pas null
		 *	Sortie : rien
		 *	Postcondition : les données de la matrice pMATDmatrice correspondent à celles du fichier pFICfichier
		 */
        void FICprincipale();

	//FONCTION D AFFICHAGE DE LA MATRICE
		/*
		 *	Methode d'afficher le contenu de pMATDmatrice a l'ecran
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : affichage de la matrice a l'ecran
		 */
		void FICafficherMatrice();

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