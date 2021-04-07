#define CEXCEPTIONH
#include <iostream>

class CException {
	//attributs
	private:
		unsigned int uiEXCId;
		char pcEXCCommentaire[80];
	//constructeurs et destructeurs
	public:
		inline CException() { uiEXCId = pcEXCCommentaire[0] = 0; };
		inline ~CException() {};
	//accesseurs et mutateurs
	public:
		inline const unsigned int EXCGetId() const { return uiEXCId; };
		inline const char* EXCGetCommentaire() const { return pcEXCCommentaire; };
		inline void EXCSetId(const unsigned int cuiArg) { uiEXCId = cuiArg; };
		void EXCSetCommentaire(const char* pccArg);
	//methodes
	public:
		bool EXCGestionaireException() const;
};
