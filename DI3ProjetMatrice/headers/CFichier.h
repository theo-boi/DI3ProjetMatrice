#define CFICHIERH

#ifndef CMATRICEH
#include "CMatrice.h"
#endif

#include <iostream>

class CFichier {
	//attributs
	private:
		const char* pcFICnom; //le nom du fichier
		FILE* pFICfichier; //pointeur pour la lecture du fichier
		CMatrice<double>* pMATDmatrice; //pointeur sur un objet CMatrice<double>


	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur par defaut permettant d'initialiser un CFichier
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : FICNew : CFichier
		 *	Postcondition : Les attributs de l'objet CFichier sont alloues/initialises
		 */
		CFichier();

		/*
		 *	Constructeur de recopie
		 *
		 *	Entree : FICarg : CFichier
		 *	Precondition : FICarg existe et est alloue
		 *	Sortie : FICNew : CFichier
		 *	Postcondition : Les attributs de l'objet FICNew sont alloues/initialises et possèdent la même valeur que ceux de FICarg
		 */
		CFichier(CFichier &FICarg);

		/*
		 *	Constructeur prenant en argument le nom d'un fichier
		 *
		 *	Entree : pcNomFichier : *caractere
		 *	Precondition : pcNomFichier existe
		 *	Sortie : FICNew : CFichier
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


	//accesseurs et mutateurs
	public:

		/*
		 *	Methode INLINE sans argument de type accesseur prenant en argument un pointeur sur une chaine de caractère pcNomFichier
		 *
		 *	Entree : pcNomFichier : *caractere
		 *	Precondition : pcNomFichier existe
		 *	Sortie : Rien
		 *	Postcondition : {pcFICnom = pcNomFichier}
		 */
		void FICsetNomFichier(const char* pcNomFichier) { pcFICnom = pcNomFichier; }

		/*
		 *	Methode INLINE sans argument de type accesseur sans argument permettant de récupérer l'objet pcFICnom et de le stocker en mémoire
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : pcNew : *caractere
		 *	Postcondition : {pcNew = pcFICnom}
		 */
		const char* FICgetNomFichier() { return pcFICnom; }

		/*
		 *	Methode INLINE sans argument de type accesseur sans argument permettant de récupérer l'objet pMATDmatrice et de le stocker en mémoire
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MATDnew : CMatrice<double>
		 *	Postcondition : {MATDnew = *pMATDmatrice}
		 */
		CMatrice<double> FICgetCMatrice() { return *pMATDmatrice; }

		/*
		 *	Methode INLINE de type accesseur a deux arguments renvoyant l'element de pMATDmatrice de coordonnees (uiX, uiY)
		 *	Remarques :
		 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiX : entier non signe, uiY : entier non signe
		 *	Precondition : (uiX < CFichier.pMATDmatrice.eMATdimLigne)^(uiY < CFichier.pMATDmatrice.eMATdimLigne)
		 *	Sortie : dElem : double
		 *	Postcondition : {dElem = CFichier.pMATDmatrice.ppdMATElem[uiX][uiY]}
		 */
		double FICgetCMatriceElem(const unsigned int uiX, const unsigned int uiY) { return pMATDmatrice->MATgetElem(uiX, uiY); }


	//operateurs
	public:

		/*
		 *	Methode de type operateur a un argument recopiant le CFichier FICarg
		 *
		 *	Entree : FICarg : CFichier
		 *	Precondition : neant
		 *	Sortie : FICEgal : CFichier
		 *	Postcondition : {FICEgal = FICarg}
		 */
		CFichier& operator=(CFichier &FICarg);


	//autres methodes
	public:

		/*
		 *	Methode sans argument renvoyant 0 une fois finie, permettant d'instancier la matrice double depuis un pattern specifique dans le fichier
		 *
		 *	Entree : rien
		 *	Precondition : { (pcFICnom != nil)^(pFICfichier != nil) }
		 *	Sortie : rien
		 *	Postcondition : les données de la matrice pMATDmatrice correspondent à celles du fichier pFICfichier
		 */
        int FICparcourir() throw(CException);

		/*
		 *	Methode INLINE sans argument affichant le contenu de la matrice MATDmatrice a l'ecran
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : affichage de la matrice a l'ecran
		 */
		void FICprintCMatrice() { pMATDmatrice->MATprint(); }
};
