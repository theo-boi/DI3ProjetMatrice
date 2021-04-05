#ifndef CMATRICEH
#include "CMatrice.h"
#endif 
#define CMATRICEDOUBLEH 0

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
		 *	Postcondition : Objet CMatriceDouble alloue
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
		 *	Postcondition : Objet CMatriceDouble alloue
		 */
		CMatriceDouble(const CMatriceDouble& MADArg);

		/*
		 *	Constructeur a deux arguments permettant d'initialiser une matrice de uiX x uiY elements unitaires
		 *	Remarques :
		 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiX : entier non signe, uiY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Objet CMatriceDouble alloue et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = 1)
		 */
		CMatriceDouble(const unsigned int uiX, const unsigned int uiY);

		/*
		 *	Destructeur
		 *
		 *	Entree : MADInutile : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Objet CMatriceDouble libere
		 */
		~CMatriceDouble();


	//operateurs
	public:

		/*
		 *	Methode de type operateur a un argument renvoyant le produit d'un objet CMatriceDouble par un nombre constant clfArg
		 *	Remarques :
		 *		- clfArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *		- clfArg est de type long double pour ne pas perdre d'information dans le cas d'une conversion
		 *
		 *	Entree : MADActuelle : CMatriceDouble, clfArg : long double
		 *	Precondition : neant
		 *	Sortie : MADMult : CMatriceDouble
		 *	Postcondition : {MADMult = MADActuelle * clfArg}
		 */
		virtual CMatriceDouble& operator*(const long double clfArg) const;

		/*
		 *	Methode de type operateur a un argument renvoyant le resultat de la division d'un objet CMatriceDouble par un nombre constant clfArg
		 *	Remarques :
		 *		- clfArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *		- clfArg est de type long double pour ne pas perdre d'information dans le cas d'une conversion
		 *
		 *	Entree : MADActuelle : CMatriceDouble, clfArg : long double
		 *	Precondition : neant
		 *	Sortie : MADDiv : CMatriceDouble
		 *	Postcondition : {MADDiv = MADActuelle / clfArg}
		 */
		virtual CMatriceDouble& operator/(const long double clfArg) const;


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
		inline void MADSetElem(const unsigned int uiX, const unsigned int uiY, const long double cldElem);


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
		CMatriceDouble& MADt() const;

		/*
		 *	Methode a un argument renvoyant la matrice additionnee par MATArg
		 *
		 *	Entree : MATArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MATAdd : CMatriceDouble
		 *	Postcondition : {MATAdd = MATActuelle + MATArg}
		 */
		CMatriceDouble& MADAdd(const CMatriceDouble& MADArg) const;

		/*
		 *	Methode a un argument renvoyant la matrice soustraite par MATArg
		 *
		 *	Entree : MATArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MATSous : CMatriceDouble
		 *	Postcondition : {MATSous = MATActuelle - MATArg}
		 */
		CMatriceDouble& MADSous(const CMatriceDouble& MADArg) const;

		/*
		 *	Methode a un argument renvoyant la matrice multipliee par MATArg
		 *
		 *	Entree : MATArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADMult : CMatriceDouble
		 *	Postcondition : {MADMult = MATActuelle * MATArg}
		 */
		CMatriceDouble& MADMult(const CMatriceDouble& MADArg) const;
};


/* Methodes INLINE */

void CMatriceDouble::MADSetElem(const unsigned int uiX, const unsigned int uiY, const long double cldElem) {
	//SI MISE EN PLACE D'UN TEMPLATE : Effectuer un try pour lever les erreurs de conversion si type(cldElem) est trop different
	const double dElem = (const double) cldElem;
	
	//set
	ppdMADElem[uiX][uiY] = dElem;
}