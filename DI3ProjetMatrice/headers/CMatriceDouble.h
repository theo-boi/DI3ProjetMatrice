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
		CMatriceDouble(unsigned int eArg1, unsigned int eArg2);
		CMatriceDouble(CMatriceDouble& MADArg) {};
		~CMatriceDouble();
	//operateurs
	public:
		virtual CMatriceDouble& operator=(float fConst) { return *new CMatriceDouble(); };
		virtual CMatriceDouble& operator*(float fConst) { return *new CMatriceDouble(); };
		virtual CMatriceDouble& operator/(float fConst) { return *new CMatriceDouble(); };
	//accesseurs
	public:
		virtual double MATGet(unsigned int x, unsigned int y);
	//autres methodes
	public:
		virtual void MATPrint(); //ou MATAfficher
		virtual CMatriceDouble& MATt(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATTransposee
		virtual CMatriceDouble& MATAdd(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATTransposee
		virtual CMatriceDouble& MATSub(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATSoustraction
		virtual CMatriceDouble& MATMult(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATMultiplication
		virtual CMatriceDouble& MATDiv(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATDivision
};
