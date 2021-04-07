#define CMATRICEH
#ifndef CEXCEPTIONH
#include "../headers/CException.h"
#endif
#include "CMatrice.cpp"
#include <iostream>

class CMatrice {
	//attributs
	protected:
		unsigned int uiMATdimLigne; //nombre de lignes de la matrice
		unsigned int uiMATdimColonne; //nombre de colonnes de la matrice

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

		/*
		 *	Methode INLINE de type mutateur a trois arguments attribuant au nombre de colonne de la matrice la valeur uiDimLigne
		 *
		 *	Entree : uiDimLigne : entier non signe
		 *	Precondition : neant
		 *	Sortie : neant
		 *	Postcondition : (uiDimLigne = uiMATDimLigne)
		 */
		virtual void MATSetDimLigne(const unsigned int uiDimLigne) { uiMATdimLigne = uiDimLigne; };

		/*
		 *	Methode INLINE de type mutateur a trois arguments attribuant au nombre de colonne de la matrice la valeur uiDimColonne
		 *
		 *	Entree : uiDimColonne : entier non signe
		 *	Precondition : neant
		 *	Sortie : neant
		 *	Postcondition : (uiDimColonne = uiMATdimColonne)
		 */
		virtual void MATSetDimColonne(const unsigned int uiDimColonne) { uiMATdimColonne = uiDimColonne; };


	//methodes
	public:
		virtual void MATPrint(bool bEndl) const =0;
};
