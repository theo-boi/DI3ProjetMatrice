#ifndef CMATRICEH
#include "CMatrice.h"
#endif 
#define CMATRICEDOUBLEH 0

/* Attention developpeurs : definitions inline predefinies a enlever. Presentes uniquement pour eviter les erreurs de compilation. */
class CMatriceDouble : public CMatrice {
	//atributs
	private:
		double** ppdMAIElem;
	//constructeurs et destructeurs
	public:
		CMatriceDouble();
		/*
			Constructeur a deux arguments permettant d'initialiser une matrice nulle de uiArgX x uiArgY elements

			Entree : uiArgX : entier non signe, uiY : entier non signe
			Precondition : neant
			Sortie : CMatriceDouble
			Postcondition : pour tout uiX < uiArgX et uiX < uiArgY, (ppdMAIElem[uiX][uiX] == 0)
		*/
		CMatriceDouble(unsigned int uiArgX, unsigned int uiArgY);
		CMatriceDouble(CMatriceDouble& MADArg);
		~CMatriceDouble();
	//operateurs
	public:
		virtual CMatriceDouble& operator=(float fConst) { return *new CMatriceDouble(); };
		virtual CMatriceDouble& operator*(float fConst) { return *new CMatriceDouble(); };
		virtual CMatriceDouble& operator/(float fConst) { return *new CMatriceDouble(); };
	//accesseurs
	public:
		/*
			Methode de type accesseur a deux arguments renvoyant l'element de coordonnees (uiArgX, uiArgY)
			
			Entree : uiArgX : entier non signe, uiArgY : entier non signe
			Precondition : (uiArgX < eMATdimLigne)^(uiArgY < eMATdimLigne)
			Sortie : dMAIElem : double
			Postcondition : (dMAIElem = ppdMAIElem[uiArgX][uiArgY])
		*/
		double MATGet(unsigned int uiArgX, unsigned int uiArgY) { return ppdMAIElem[uiArgX][uiArgY]; };
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
