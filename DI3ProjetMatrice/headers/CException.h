#pragma warning( disable : 4290 )
#define CEXCEPTIONH
#include <iostream>

class CException {
	//attributs
	private:
		unsigned int uiEXCId; //Id de l'exception
		const char* pcEXCCommentaire; //Commentaire sur l'exception


	//constructeurs et destructeurs
	public:

		/*
		 *	Constructeur INLINE par defaut permettant d'initialiser une exception
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : ExcNew : CException
		 *	Postcondition : Attributs de CException initialises
		 */
		inline CException();

		/*
		 *	Destructeur INLINE
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

		/*
		 *	Methode INLINE de type mutateur sans arguments attribuant a l'id la valeur uiArg
		 *	Remarques :
		 *		- uiArg est constant car il ne doit pas etre modifie durant l'execution de la methode
		 *
		 *	Entree : uiArg : entier non signe
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : {uiEXCId = uiArg}
		 */
		inline void EXCSetId(const unsigned int uiArg) { uiEXCId = uiArg; };

		/*
		 *	Methode INLINE de type mutateur sans arguments attribuant au commentaire la chaine de caracteres pcArg
		 *	Remarques :
		 *		- uiArg est constant car il ne doit pas etre modifie durant l'execution de la methode
		 *
		 *	Entree : pcArg : *caractere
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : {pcEXCCommentaire = pcArg}
		 */
		void EXCSetCommentaire(const char* pcArg) { pcEXCCommentaire = pcArg; };


	//methodes
	public:

		/*
		 *	Methode sans argument gerant une exception
		 *
		 *	Entree : rien
		 *	Precondition : neant
		 *	Sortie : rien
		 *	Postcondition : L'objet CException est gere sinon il est a nouveau releve
		 */
		void EXCGestionaireException() const throw(CException);
};

CException::CException() {
	uiEXCId = 0;
	pcEXCCommentaire = "";
}
