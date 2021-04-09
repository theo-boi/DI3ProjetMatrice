#define CMADRICEDOUBLEH
#ifndef CMATRICESTRUCTUREH
#include "CMatriceStructure.h"
#endif

class CMatriceDouble : public CMatriceStructure {
	//attributs
	private:
		double** ppdMADelem; //tableau des elements de la matrice


	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur par defaut permettant d'initialiser une matrice de 0 elements
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Les attributs de l'objet CMatriceDouble sont alloues/initialises
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
		 *	Postcondition : Les attributs de l'objet CMatriceDouble sont alloues/initialises
		 */
		CMatriceDouble(const CMatriceDouble& MADArg) throw(CException);

		/*
		 *	Constructeur de recopie
		 *	Remarques :
		 *		- MAGArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MAGArg : CMatriceStructure
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Les attributs de l'objet CMatriceDouble sont alloues/initialises
		 */
		CMatriceDouble(const CMatriceStructure& MAGArg) { CMatriceDouble((CMatriceDouble&) MAGArg); };

		/*
		 *	Constructeur a deux arguments permettant d'initialiser une matrice de uiX x uiY elements unitaires
		 *	Remarques :
		 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiX : entier non signe, uiY : entier non signe
		 *	Precondition : neant
		 *	Sortie : MADNew : CMatriceDouble
		 *	Postcondition : Les attributs de l'objet CMatriceDouble sont alloues/initialises et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = 1)
		 */
		CMatriceDouble(const unsigned int uiX, const unsigned int uiY);

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Les attributs de l'objet CMatriceDouble sont liberes
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
		 *	Precondition : (uiX < eMADdimLigne)^(uiY < eMADdimLigne)
		 *	Sortie : dElem : double
		 *	Postcondition : {dElem = ppdMAIElem[uiX][uiY]}
		 */
		inline double MADgetElem(const unsigned int uiX, const unsigned int uiY) const throw(CException);

		/*
		 *	Methode INLINE de type mutateur a trois arguments attribuant a l'element de coordonnees (uiX, uiY) la valeur dElem
		 *	Remarques :
		 *		- uiX et uiY sont constants car ils ne doivent pas etre modifies durant l'execution de la methode
		 *
		 *	Entree : uiX : entier non signe, uiY : entier non signe, dElem : double
		 *	Precondition : (uiX < eMADdimLigne)^(uiY < eMADdimLigne)
		 *	Sortie : rien
		 *	Postcondition : {ppdMAIElem[uiX][uiY] = dElem}
		 */
		inline void MADsetElem(const unsigned int uiX, const unsigned int uiY, const long double ldElem) throw(CException);


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
		 *	Methode de type operateur a un argument renvoyant la matrice additionnee par une CMatriceDouble MADArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MADArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADAdd : CMatriceDouble
		 *	Postcondition : {MADAdd = MADActuelle + MADArg}
		 */
		CMatriceDouble operator+(const CMatriceDouble& MADArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice soustraite par une CMatriceDouble MADArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MADArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADSous : CMatriceDouble
		 *	Postcondition : {MADSous = MADActuelle - MADArg}
		 */
		CMatriceDouble operator-(const CMatriceDouble& MADArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument renvoyant la matrice multipliee par une CMatriceDouble MADArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MADArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADMult : CMatriceDouble
		 *	Postcondition : {MADMult = MADActuelle * MADArg}
		 */
		CMatriceDouble operator*(const CMatriceDouble& MADArg) const throw(CException);

		/*
		 *	Methode de type operateur a un argument recopiant la matrice MADArg
		 *		- MADArg est constant car il ne doit pas etre modifie lors de l'execution de la methode
		 *
		 *	Entree : MADArg : CMatriceDouble
		 *	Precondition : neant
		 *	Sortie : MADActuelle : CMatriceDouble
		 *	Postcondition : {MADActuelle = MADArg}
		 */
		CMatriceDouble& operator=(const CMatriceDouble& MADArg) throw(CException);


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
		virtual void MATprint(const bool bEndl = 0) const;

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
CMatriceDouble operator*(const long double cldArg, const CMatriceDouble MADArg) throw(CException);


/* Methodes INLINE */

double CMatriceDouble::MADgetElem(const unsigned int uiX, const unsigned int uiY) const throw(CException) {
	//Effectuer un try pour lever les erreurs de conversion si uiX ou uiY sont trop grands
	if (uiX >= uiMATdimLigne || uiY >= uiMATdimColonne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("MADgetElem (valeurs des arguments incoherents)");
		throw(EXCconversion);
	}

	return ppdMADelem[uiX][uiY];
}

void CMatriceDouble::MADsetElem(const unsigned int uiX, const unsigned int uiY, const long double ldElem) throw(CException) {
	//Effectuer un try pour lever les erreurs de conversion si type(cldElem) est trop different
	try { (const double) ldElem; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("MADsetElem (type de l'argument incompatible)");
		throw(EXCconversion);
	}
	//Effectuer un try pour lever les erreurs de conversion si uiX ou uiY sont trop grands
	if (uiX >= uiMATdimLigne || uiY >= uiMATdimColonne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("MADgetElem (valeurs des arguments incoherents)");
		throw(EXCconversion);
	}

	//set
	ppdMADelem[uiX][uiY] = (const double) ldElem;
}
