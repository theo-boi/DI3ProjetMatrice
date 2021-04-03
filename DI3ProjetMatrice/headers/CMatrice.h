#define CMATRICEH 0

class CMatrice {

	//attributs
	protected:
		unsigned int uiMATdimLigne;
		unsigned int uiMATdimColonne;

	//accesseurs et mutateurs
	public:

		/*
			Methode INLINE de type accesseur sans arguments renvoyant le nombre de ligne

			Entree : rien
			Precondition : neant
			Sortie : uiDimLigne : entier non signe
			Postcondition : (uiDimLigne = uiMATDimLigne)
		*/
		virtual unsigned int MATGetDimLigne() { return uiMATdimLigne; };

		/*
			Methode INLINE de type accesseur sans arguments renvoyant le nombre de colonne

			Entree : rien
			Precondition : neant
			Sortie : uiDimColonne : entier non signe
			Postcondition : (uiDimColonne = uiMATdimColonne)
		*/
		virtual unsigned int MATGetDimColonne() { return uiMATdimColonne; };


	//operateurs
	public:
		//Type long double pour ne pas perdre d'information dans le cas de la conversion d'un nombre
		virtual CMatrice& operator*(const long double clfConst)=0;
		virtual CMatrice& operator/(const long double clfConst)=0;


	//accesseurs et mutateurs
	public:
		/*type void a adapter dans les classes filles*/
		//doivent etre declares dans la classe fille car le type de retour void ne peut pas etre adapte


	//methodes
	public:
		/*type CMatrice& a adapter dans les classes filles*/
		virtual void MATPrint(bool bEndl)=0; //ou MATAfficher
		virtual CMatrice& MATt(const CMatrice* pMATarg)=0; //ou MATTransposee
		virtual CMatrice& MATAdd(const CMatrice* pMATarg)=0; //ou MATTransposee
		virtual CMatrice& MATSous(const CMatrice* pMATarg)=0; //ou MATSoustraction
		virtual CMatrice& MATMult(const CMatrice* pMATarg)=0; //ou MATMultiplication
		virtual CMatrice& MATDiv(const CMatrice* pMATarg)=0; //ou MATDivision
};
