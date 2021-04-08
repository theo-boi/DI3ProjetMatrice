#define CMATRICEH
#ifndef CMATRICEGENERIQUEH
#include "CMatriceStructure.h"
#endif

template<class T>
class CMatrice : public CMatriceStructure {
	//attributs
	private:
		T** ppdMATelem; //tableau des elements de la matrice


	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur par defaut permettant d'initialiser une matrice de 0 elements
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MATNew : CMatrice
		 *	Postcondition : Les attributs de l'objet CMatrice sont alloues/initialises
		 */
		CMatrice();

		/*
		 *	Constructeur de recopie
		 *	Remarques :
		 *		- MATArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATArg : CMatrice<T2>
		 *	Precondition : neant
		 *	Sortie : MATNew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> MATNew sont alloues/initialises
		 */
		template<class T2>
		CMatrice(CMatrice<T2>& MADArg) throw(CException);

		/*
		 *	Constructeur a deux arguments permettant d'initialiser une matrice de uiArgX x uiArgY elements nuls
		 *	Remarques :
		 *		- uiArgX et uiArgY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiArgX : entier non signe, uiArgY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MATNew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> MATNew sont alloues/initialises et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = T())
		 */
		CMatrice(const unsigned int uiX, const unsigned int uiY);

		/*
		 *	Constructeur a trois arguments permettant d'initialiser une matrice de uiArgX x uiArgY elements dont la valeur est T2elem
		 *	Remarques :
		 *		- uiArgX et uiArgY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiArgX : entier non signe, uiArgY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MATNew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> MATNew sont alloues/initialises et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = T2elem)
		 */
		template<class T2>
		CMatrice(const unsigned int uiX, const unsigned int uiY, T2 T2elem) throw(CException);

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Les attributs de l'objet CMatrice sont liberes
		 */
		~CMatrice();


	//accesseurs et mutateurs
	public:

		/*
		 *	Methode de type accesseur a deux arguments renvoyant l'element de coordonnees (uiArgX, uiArgY)
		 *	Remarques :
		 *		- uiArgX et uiArgY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiArgX : entier non signe, uiArgY : entier non signe
		 *	Precondition : (uiArgX < eMATdimLigne)^(uiArgY < eMATdimLigne)
		 *	Sortie : dElem : double
		 *	Postcondition : {dElem = ppdMAIElem[uiArgX][uiArgY]}
		 */
		T MATgetElem(const unsigned int uiArgX, const unsigned int uiArgY) const throw(CException);

		/*
		 *	Methode de type mutateur a trois arguments attribuant a l'element de coordonnees (uiArgX, uiArgY) la valeur dElem
		 *	Remarques :
		 *		- uiArgX et uiArgY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiArgX : entier non signe, uiArgY : entier non signe, dElem : double
		 *	Precondition : (uiArgX < eMATdimLigne)^(uiArgY < eMATdimLigne)
		 *	Sortie : rien
		 *	Postcondition : {ppdMAIElem[uiArgX][uiArgY] = dElem}
		 */
		template<class T2>
		void MATsetElem(const unsigned int uiArgX, const unsigned int uiArgY, T2 T2elem) throw(CException);


	//operateurs
	public:

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice multipliee par un nombre constant T2 T2arg
		 *	Remarques :
		 *		- T2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : T2arg : T2
		 *	Precondition : neant
		 *	Sortie : MATmult : CMatrice
		 *	Postcondition : {MATmult = MATactuelle * T2arg}
		 */
		template<class T2>
		CMatrice<T> operator*(const T2 T2arg) const throw(CException) { return *this; };

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice divisee par un nombre constant  T2 T2arg
		 *	Remarques :
		 *		- T2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : T2arg : T2
		 *	Precondition : neant
		 *	Sortie : MATdiv : CMatrice
		 *	Postcondition : {MATdiv = MATactuelle / T2arg}
		 */
		template<class T2>
		CMatrice<T> operator/(const T2 T2arg) const throw(CException) { return *this; };

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice additionnee par une CMatrice<T2> MAT2arg
		 *		- MAT2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MAT2arg : CMatrice
		 *	Precondition : neant
		 *	Sortie : MATadd : CMatrice
		 *	Postcondition : {MATadd = MATactuelle + MAT2arg}
		 */
		template<class T2>
		CMatrice<T> operator+(const CMatrice<T2>& MAT2arg) const throw(CException) { return *this; };

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice soustraite par une CMatrice<T2> MAT2arg
		 *		- MAT2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MAT2arg : CMatrice
		 *	Precondition : neant
		 *	Sortie : MATsous : CMatrice
		 *	Postcondition : {MATsous = MATactuelle - MAT2arg}
		 */
		template<class T2>
		CMatrice<T> operator-(const CMatrice<T2>& MAT2arg) const throw(CException) { return *this; };

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice multipliee par une CMatrice<T2> MAT2arg
		 *		- MAT2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MAT2arg : CMatrice<T2>
		 *	Precondition : neant
		 *	Sortie : MATmult : CMatrice<T>
		 *	Postcondition : {MATmult = MATactuelle * MAT2arg}
		 */
		template<class T2>
		CMatrice<T> operator*(const CMatrice<T2>& MAT2arg) const throw(CException) { return *this; };

		/*
		 *	Methode de type operateur a un argument recopiant la matrice CMatrice<T2> MAT2arg
		 *		- MAT2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MAT2arg : CMatrice<T2>
		 *	Precondition : neant
		 *	Sortie : MATactuelle : CMatrice<T>
		 *	Postcondition : {MATactuelle = MAT2arg}
		 */
		template<class T2>
		CMatrice<T>& operator=(const CMatrice<T2>& MAT2arg) throw(CException);


	//autres methodes
	public:

		/*
		 *	Methode sans argument affichant la matrice (puis un saut de ligne si bEndl est vrai)
		 *
		 *	Entree : bEndl : booleen
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Affiche les elements de MATactuelle
		 */
		virtual void MATprint(const bool bEndl = 0) const;

		/*
		 *	Methode sans argument renvoyant la transposee de la matrice
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MATt : CMatrice<T>
		 *	Postcondition : MATt est la transposee de MATactuelle
		 */
		CMatrice<T> MATt() const;
};

/*
 *	Methode de type operateur a deux argument renvoyant un nombre constant T2 T2arg multiplie par la matrice CMatrice<T2> MAT2arg
 *	Remarques :
 *		- T2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
 *
 *	Entree : T2arg : T2, MAT2arg : CMatrice<T2>
 *	Precondition : neant
 *	Sortie : MATmult : CMatrice<T>
 *	Postcondition : {MATmult = T2arg * MAT2arg}
 */
template<class T, class T2>
CMatrice<T> operator*(const T2 T2arg, const CMatrice<T2> MAT2arg) throw(CException) { return this; };


/* Definitions des methodes */

#include "CMatrice.inc.h"
