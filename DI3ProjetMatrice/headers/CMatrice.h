#define CMATRICEH
#ifndef CEXCEPTIONH
#include "../headers/CException.h"
#endif
#ifndef CMATRICECPP
#include "CMatrice.cpp"
#endif
#include <iostream>

class CMatrice {
	//attributs
	protected:
		unsigned int uiMATdimLigne;
		unsigned int uiMATdimColonne;

	//accesseurs et mutateurs
	public:

		/*
		 *	Methode INLINE de type accesseur sans arguments renvoyant le nombre de ligne
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : uiDimLigne : entier non signe
		 *	Postcondition : (uiDimLigne = uiMATDimLigne)
		 */
		virtual unsigned int MATGetDimLigne() const { return uiMATdimLigne; };

		/*
		 *	Methode INLINE de type accesseur sans arguments renvoyant le nombre de colonne
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : uiDimColonne : entier non signe
		 *	Postcondition : (uiDimColonne = uiMATdimColonne)
		 */
		virtual unsigned int MATGetDimColonne() const { return uiMATdimColonne; };


	//methodes
	public:
		virtual void MATPrint(bool bEndl) const =0;
};
