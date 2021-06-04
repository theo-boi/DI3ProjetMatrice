#define CMATRICEH
#ifndef CMATRICESTRUCTUREH
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
		 *	Sortie : MATnew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> sont alloues/initialises
		 */
		CMatrice();

		/*
		 *	Constructeur de recopie
		 *	Remarques :
		 *		- MATArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATArg : CMatrice<T>
		 *	Precondition : neant
		 *	Sortie : MATnew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> MATnew sont alloues/initialises
		 */
		CMatrice(const CMatrice<T>& MADArg) throw(CException);

		/*
		 *	Constructeur a deux arguments permettant d'initialiser une matrice de uiArgX x uiArgY elements nuls
		 *	Remarques :
		 *		- uiArgX et uiArgY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiArgX : entier non signe, uiArgY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MATnew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> MATnew sont alloues/initialises et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = T())
		 */
		CMatrice(const unsigned int uiX, const unsigned int uiY);

		/*
		 *	Constructeur template a trois arguments permettant d'initialiser une matrice de uiArgX x uiArgY elements dont la valeur est T2elem
		 *	Remarques :
		 *		- uiArgX et uiArgY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiArgX : entier non signe, uiArgY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MATnew : CMatrice<T>
		 *	Postcondition : Les attributs de l'objet CMatrice<T> MATnew sont alloues/initialises et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = T2elem)
		 */
		template<class T2>
		CMatrice(const unsigned int uiX, const unsigned int uiY, T2 T2elem) throw(CException);

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Les attributs de l'objet CMatrice<T> sont liberes
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
		 *	Methode template de type mutateur a trois arguments attribuant a l'element de coordonnees (uiArgX, uiArgY) la valeur dElem
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
		 *	Methode template INLINE de type operateur de conversion renvoyant la conversion d'une matrice CMatrice<T> en une matrice CMatrice<T2>
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MAT2new : CMatrice<T2>
		 *	Postcondition : {MAT2new = (CMatrice<T2>) MATactuelle}
		 */
		template<class T2>
		operator CMatrice<T2>() throw(CException) {
			//Leve l'exception de conversion si type trop different
			try { (T2) MATgetElem(0, 0); }
			catch (CException EXCLevee) { std::cout << EXCLevee.EXCGetCommentaire(); }
			catch (...) {
				CException EXCconversion;
				EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
				EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
				throw(EXCconversion);
			}

			//init
			CMatrice<T2> MAT2 = CMatrice<T2>(MATgetDimLigne(), MATgetDimColonne()); //objet temporaire

			//recopie des elements de la matrice dans MAT2
			for (unsigned int uiBoucleForX = 0; uiBoucleForX < MAT2.MATgetDimLigne(); uiBoucleForX++) {
				for (unsigned int uiBoucleForY = 0; uiBoucleForY < MAT2.MATgetDimColonne(); uiBoucleForY++) {
					//conversion de chaque element T en T2 puis recopie a l'emplacement (uiBoucleForX,uiBoucleForY) de MAT2
					MAT2.MATsetElem(uiBoucleForX, uiBoucleForY, (T2)MATgetElem(uiBoucleForX, uiBoucleForY));
				}
			}

			return MAT2; //passage par valeur : MAT2 est recopie
		}

		/*
		 *	Methode de type operateur a un argument recopiant la matrice CMatrice<T> MATarg
		 *		- MATarg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATarg : CMatrice<T>
		 *	Precondition : neant
		 *	Sortie : MATactuelle : CMatrice<T>
		 *	Postcondition : {MATactuelle = MAT2arg}
		 */
		CMatrice<T>& operator=(const CMatrice<T>& MATarg) throw(CException);

		/*
		 *	Methode template de type operateur a un argument renvoyant la matrice multipliee par un nombre constant T2 T2arg
		 *	Remarques :
		 *		- T2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : T2arg : T2
		 *	Precondition : neant
		 *	Sortie : MATmult : CMatrice<T>
		 *	Postcondition : {MATmult = MATactuelle * T2arg}
		 */
		template<class T2>
		CMatrice<T> operator*(const T2 T2arg) const throw(CException);

		/*
		 *	Methode template de type operateur a un argument renvoyant la matrice divisee par un nombre constant  T2 T2arg
		 *	Remarques :
		 *		- T2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : T2arg : T2
		 *	Precondition : neant
		 *	Sortie : MATdiv : CMatrice<T>
		 *	Postcondition : {MATdiv = MATactuelle / T2arg}
		 */
		template<class T2>
		CMatrice<T> operator/(const T2 T2arg) const throw(CException);

		/*
		 *	Methode template de type operateur a un argument renvoyant la matrice additionnee par une CMatrice<T> MATarg
		 *		- MATarg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATarg : CMatrice<T>
		 *	Precondition : neant
		 *	Sortie : MATadd : CMatrice<T>
		 *	Postcondition : {MATadd = MATactuelle + MATarg}
		 */
		CMatrice<T> operator+(const CMatrice<T>& MATarg) const throw(CException);

		/*
		 *	Methode template de type operateur a un argument renvoyant la matrice soustraite par une CMatrice<T> MATarg
		 *		- MATarg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATarg : CMatrice<T>
		 *	Precondition : neant
		 *	Sortie : MATsous : CMatrice<T>
		 *	Postcondition : {MATsous = MATactuelle - MATarg}
		 */
		CMatrice<T> operator-(const CMatrice<T>& MATarg) const throw(CException);

		/*
		 *	Methode template de type operateur a un argument renvoyant la matrice multipliee par une CMatrice<T> MATarg
		 *		- MATarg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATarg : CMatrice<T>
		 *	Precondition : neant
		 *	Sortie : MATmult : CMatrice<T>
		 *	Postcondition : {MATmult = MATactuelle * MATarg}
		 */
		CMatrice<T> operator*(const CMatrice<T>& MATarg) const throw(CException);


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

		/**
		 * Methode sans argument regardant si une matrice est de Vandermonde.
		 * 
		 * Entree : rien
		 * Precondition : neant
		 * Sortie : booleen
		 * Postcondition : Renvoie vrai si la matrice est de Vandermonde, faux sinon
		 */
		bool MATisVandermonde() const;

		/*
		 *	Methode sans argument renvoyant le determinant de la matrice de Vandermonde.
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : iDet : double
		 *	Postcondition : iDet est le determinant de la matrice de Vandermonde
		 */
		double MATVandermondeDet() const;
};

/*
 *	Methode de type operateur a deux argument renvoyant un nombre constant T2 T2arg multiplie par la matrice CMatrice<T> MATarg
 *	Remarques :
 *		- T2arg est constant car il ne doit pas etre modifie lors de l'execution de la methode
 *
 *	Entree : T2arg : T2, MATarg : CMatrice<T>
 *	Precondition : neant
 *	Sortie : MATmult : CMatrice<T>
 *	Postcondition : {MATmult = T2arg * MATarg}
 */
template<class T, class T2>
CMatrice<T> operator*(const T2 T2arg, const CMatrice<T>& MATarg) throw(CException);


/* Definitions des methodes */

#include "CMatrice.inc.h"

template class CMatrice<double>;
