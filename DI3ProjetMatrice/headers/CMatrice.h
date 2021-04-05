#define CMATRICEH 0

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


	//operateurs
	public:
		//Type long double pour ne pas perdre d'information dans le cas de la conversion d'un nombre
		virtual CMatrice& operator*(const long double clfConst) const =0;
		virtual CMatrice& operator/(const long double clfConst) const =0;


	//accesseurs et mutateurs
	public:


	//methodes
	public:
		virtual void MATPrint(bool bEndl) const =0; //ou MATAfficher
};
