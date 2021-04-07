#define CEXCEPTIONH
#include <iostream>

class CException {
	//attributs
	private:
		unsigned int uiEXCId;
		char pcEXCCommentaire[80];
	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur par defaut permettant d'initialiser une exception
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : ExcNew : CException
		 *	Postcondition : Attributs de CException initialises
		 */
		inline CException() { uiEXCId = pcEXCCommentaire[0] = 0; };

		/*
		 *	Destructeur
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : neant
		 */
		inline ~CException() {};
	//accesseurs et mutateurs
	public:

		/*
		 *	Methode INLINE de type accesseur sans arguments renvoyant l'id
		 *	Remarques :
		 *		- renvoie une constante car l'integrite de l'exception doit etre assuree
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : uiEXCId : entier non signe
		 *	Postcondition : neant
		 */
		inline const unsigned int& EXCGetId() const { return uiEXCId; };

		/*
		 *	Methode INLINE de type accesseur sans arguments renvoyant le commentaire
		 *	Remarques :
		 *		- renvoie une constante car l'integrite de l'exception doit etre assuree
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : pcEXCCommentaire : *caractere
		 *	Postcondition : neant
		 */
		inline const char* EXCGetCommentaire() const { return pcEXCCommentaire; };
		inline void EXCSetId(const unsigned int cuiArg) { uiEXCId = cuiArg; };
		void EXCSetCommentaire(const char* pccArg);
	//methodes
	public:
		bool EXCGestionaireException() const;
};
