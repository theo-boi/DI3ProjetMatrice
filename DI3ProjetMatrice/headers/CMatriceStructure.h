#define CMATRICESTRUCTUREH
#ifndef CEXCEPTIONH
#include "CException.h"
#endif
#include "CMatriceStructure.inc.h"

class CMatriceStructure {
	//attributs
	protected:
		unsigned int uiMATdimLigne; //nombre de lignes de la matrice
		unsigned int uiMATdimColonne; //nombre de colonnes de la matrice


	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur par defaut permettant d'initialiser la structure d'une matrice de 0 elements
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : MASNew : CMatriceStructure
		 *	Postcondition : Les attributs de MASNew (propres a CMatriceStructure) sont initialises
		 */
		CMatriceStructure() { uiMATdimLigne = uiMATdimColonne = 0; };

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : Les attributs de MASNew (propres a CMatriceStructure) sont reinitialises
		 */
		~CMatriceStructure() { uiMATdimLigne = uiMATdimColonne = 0; };


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
		virtual unsigned int MATgetDimLigne() const { return uiMATdimLigne; };

		/*
		 *	Methode INLINE de type accesseur sans arguments renvoyant le nombre de colonne
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : uiDimColonne : entier non signe
		 *	Postcondition : (uiDimColonne = uiMATdimColonne)
		 */
		virtual unsigned int MATgetDimColonne() const { return uiMATdimColonne; };

		/*
		 *	Methode INLINE de type mutateur a trois arguments attribuant au nombre de colonne de la matrice la valeur uiDimLigne
		 *
		 *	Entree : uiDimLigne : entier non signe
		 *	Precondition : neant
		 *	Sortie : neant
		 *	Postcondition : (uiDimLigne = uiMATDimLigne)
		 */
		virtual void MATsetDimLigne(const unsigned int uiDimLigne) { uiMATdimLigne = uiDimLigne; };

		/*
		 *	Methode INLINE de type mutateur a trois arguments attribuant au nombre de colonne de la matrice la valeur uiDimColonne
		 *
		 *	Entree : uiDimColonne : entier non signe
		 *	Precondition : neant
		 *	Sortie : neant
		 *	Postcondition : (uiDimColonne = uiMATdimColonne)
		 */
		virtual void MATsetDimColonne(const unsigned int uiDimColonne) { uiMATdimColonne = uiDimColonne; };


	//methodes
	public:
		virtual void MATprint(const bool bEndl) const =0;
};
