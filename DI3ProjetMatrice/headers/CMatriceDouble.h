#define CMATRICEDOUBLEH
#ifndef CMATRICEH
#include "CMatrice.h"
#endif 

/*
 *	Attention developpeurs : definitions inline predefinies (non-indiquees dans la specification) a enlever.
 *	Presentes uniquement pour eviter les erreurs de compilation.
 */
class CMatriceDouble : public CMatrice {
	//attributs
	private:
		double** ppdMADElem;

	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur par defaut permettant d'initialiser une matrice de 0 elements
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Attributs de CMatriceDouble alloues/initialises
		 */
		CMatriceDouble();

		/*
		 *	Constructeur de recopie
		 *	Remarques :
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MADArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Objet CMatriceDouble alloues/initialises
		 */
		CMatriceDouble(const CMatriceDouble& MADArg) throw(CException);

		/*
		 *	Constructeur de recopie
		 *	Remarques :
		 *		- MATArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATArg : CMatrice
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Objet CMatriceDouble alloues/initialises
		 */
		CMatriceDouble(const CMatrice& MADArg) { CMatriceDouble((CMatriceDouble&) MADArg); };

		/*
		 *	Constructeur a deux arguments permettant d'initialiser une matrice de uiX x uiY elements unitaires
		 *	Remarques :
		 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiX : entier non signe, uiY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Objet CMatriceDouble alloues/initialises et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = 1)
		 */
		CMatriceDouble(const unsigned int uiX, const unsigned int uiY);

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Attributs de CMatriceDouble liberes
		 */
		~CMatriceDouble();


		//accesseurs et mutateurs
public:

	/*
	 *	Methode INLINE de type accesseur a deux arguments renvoyant l'element de coordonnees (uiX, uiY)
	 *	Remarques :
	 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
	 *
	 *	Entree : uiX : entier non signe, uiY : entier non signe
	 *	Precondition : (uiX < eMATdimLigne)^(uiY < eMATdimLigne)
	 *	Sortie : dElem : double
	 *	Postcondition : {dElem = ppdMAIElem[uiX][uiY]}
	 */
	inline double MADGetElem(const unsigned int uiX, const unsigned int uiY) const { return ppdMADElem[uiX][uiY]; };

	/*
	 *	Methode INLINE de type mutateur a trois arguments attribuant a l'element de coordonnees (uiX, uiY) la valeur dElem
	 *	Remarques :
	 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
	 *
	 *	Entree : uiX : entier non signe, uiY : entier non signe, dElem : double
	 *	Precondition : (uiX < eMATdimLigne)^(uiY < eMATdimLigne)
	 *	Sortie : rien
	 *	Postcondition : {ppdMAIElem[uiX][uiY] = dElem}
	 */
	inline void MADSetElem(const unsigned int uiX, const unsigned int uiY, const long double ldElem);


	//operateurs
	public:

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice multipliee par un nombre constant clfArg
		 *	Remarques :
		 *		- clfArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *		- clfArg est de type long double pour ne pas perdre d'information dans le cas d'une conversion
		 *
		 *	Entree : MADActuelle : CMatriceDouble, clfArg : long double
		 *	Precondition : neant
		 *	Sortie : MADMult : CMatriceDouble
		 *	Postcondition : {MADMult = MADActuelle * clfArg}
		 */
		CMatriceDouble operator*(const long double lfArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice divisee par un nombre constant clfArg
		 *	Remarques :
		 *		- clfArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *		- clfArg est de type long double pour ne pas perdre d'information dans le cas d'une conversion
		 *
		 *	Entree : MADActuelle : CMatriceDouble, clfArg : long double
		 *	Precondition : neant
		 *	Sortie : MADDiv : CMatriceDouble
		 *	Postcondition : {MADDiv = MADActuelle / clfArg}
		 */
		CMatriceDouble operator/(const long double lfArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice additionnee par une CMatriceDouble MATArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MATAdd : CMatriceDouble
		 *	Postcondition : {MATAdd = MATActuelle + MATArg}
		 */
		CMatriceDouble operator+(const CMatriceDouble& MADArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice soustraite par une CMatriceDouble MATArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MATSous : CMatriceDouble
		 *	Postcondition : {MATSous = MATActuelle - MATArg}
		 */
		CMatriceDouble operator-(const CMatriceDouble& MADArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice multipliee par une CMatriceDouble MATArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MATArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADMult : CMatriceDouble
		 *	Postcondition : {MADMult = MATActuelle * MATArg}
		 */
		CMatriceDouble operator*(const CMatriceDouble& MADArg) const throw(CException);


	//autres methodes
	public:

		/*
		 *	Methode sans argument affichant la matrice (puis un saut de ligne si bEndl est vrai)
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Affiche les elements de CMatriceDouble
		 */
		virtual void MATPrint(bool bEndl = 0) const;

		/*
		 *	Methode sans argument renvoyant la transposee de la matrice
		 *
		 *	Entree : MADActuelle : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADt : CMatriceDouble
		 *	Postcondition : MADt est la transposee de MADActuelle
		 */
		CMatriceDouble MADt() const;
};

/*
 *	Methode de type operateur a deux argument renvoyant un nombre constant clfArg multiplie par la matrice CMatriceDouble MADArg
 *	Remarques :
 *		- clfArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
 *		- clfArg est de type long double pour ne pas perdre d'information dans le cas d'une conversion
 *
 *	Entree : MADArg : CMatriceDouble, clfArg : long double
 *	Precondition : neant
 *	Sortie : MADMult : CMatriceDouble
 *	Postcondition : {MADMult = clfArg * MADArg}
 */
CMatriceDouble operator*(const long double cldArg, const CMatriceDouble MADArg);


/* Methodes INLINE */

void CMatriceDouble::MADSetElem(const unsigned int uiX, const unsigned int uiY, const long double ldElem) {
	//Effectuer un try pour lever les erreurs de conversion si type(cldElem) est trop different
	try { (const double) ldElem; }
	catch (...) {
		CException EXCConversion;
		EXCConversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCConversion.EXCSetCommentaire("MADSetElem (type de l'argument incompatible)");
		throw(EXCConversion);
	}

	//set
	ppdMADElem[uiX][uiY] = (const double) ldElem;
}
