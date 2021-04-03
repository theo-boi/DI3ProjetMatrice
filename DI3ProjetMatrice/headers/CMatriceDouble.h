#ifndef CMATRICEH
#include "CMatrice.h"
#endif 
#define CMATRICEDOUBLEH 0

/* Attention developpeurs : definitions inline predefinies (non-indiquees dans la specification) a enlever.
	Presentes uniquement pour eviter les erreurs de compilation.
*/
class CMatriceDouble : public CMatrice {
	//attributs
	private:
		double** ppdMAIElem;

	//constructeurs et destructeurs
	public:

		/*
			Constructeur par defaut permettant d'initialiser une matrice de 0 elements

			Entree : rien
			Precondition : neant
			Sortie : CMatriceDouble
			Postcondition : Objet CMatriceDouble alloue
		*/
		CMatriceDouble();

		/*
			Constructeur de recopie

			Entree : MADArg : CMatriceDouble
			Precondition : neant
			Sortie : CMatriceDouble
			Postcondition : Objet CMatriceDouble alloue
		*/
		CMatriceDouble(CMatriceDouble& MADArg);

		/*
			Constructeur a deux arguments permettant d'initialiser une matrice nulle de uiX x uiY elements

			Entree : uiX : entier non signe, uiY : entier non signe
			Precondition : neant
			Sortie : CMatriceDouble
			Postcondition : Objet CMatriceDouble alloue et pour tout uiXi < uiX et uiYi < uiY, (ppdMAIElem[uiXi][uiYi] = 0)
		*/
		CMatriceDouble(unsigned int uiX, unsigned int uiY);

		/*
			Destructeur

			Entree : CMatriceDouble
			Precondition : neant
			Sortie : rien
			Postcondition : Objet CMatriceDouble libere
		*/
		~CMatriceDouble();


	//operateurs
	public:
		virtual CMatriceDouble& operator=(float fConst) { return *new CMatriceDouble(); };
		virtual CMatriceDouble& operator*(float fConst) { return *new CMatriceDouble(); };
		virtual CMatriceDouble& operator/(float fConst) { return *new CMatriceDouble(); };


	//accesseurs et mutateurs
	public:

		/*
			Methode INLINE de type accesseur a deux arguments renvoyant l'element de coordonnees (uiX, uiY)
			
			Entree : uiX : entier non signe, uiY : entier non signe
			Precondition : (uiX < eMATdimLigne)^(uiY < eMATdimLigne)
			Sortie : dMAIElem : double
			Postcondition : (dMAIElem = ppdMAIElem[uiX][uiY])
		*/
		double MADGet(unsigned int uiX, unsigned int uiY) { return ppdMAIElem[uiX][uiY]; };

		/*
			Methode INLINE de type mutateur a trois arguments attribuant a l'element de coordonnees (uiX, uiY) la valeur dElem

			Entree : uiX : entier non signe, uiY : entier non signe, dElem : double
			Precondition : (uiX < eMATdimLigne)^(uiY < eMATdimLigne)
			Sortie : rien
			Postcondition : (ppdMAIElem[uiX][uiY] = dElem)
		*/
		void MADSet(unsigned int uiX, unsigned int uiY, double dElem) { ppdMAIElem[uiX][uiY] = dElem; };


	//autres methodes
	public:

		/*
			Methode sans argument affichant la matrice

			Entree : rien
			Precondition : neant
			Sortie : rien
			Postcondition : Affiche les elements de CMatriceDouble
		*/
		virtual void MATPrint(); //ou MATAfficher
		virtual CMatriceDouble& MATt(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATTransposee
		virtual CMatriceDouble& MATAdd(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATTransposee
		virtual CMatriceDouble& MATSub(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATSoustraction
		virtual CMatriceDouble& MATMult(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATMultiplication
		virtual CMatriceDouble& MATDiv(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATDivision
};
