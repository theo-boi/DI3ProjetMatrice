#ifndef CMATRICEH
#define CMATRICEH 0
#include "CMatrice.h"
#endif 

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
		/*type void à adapter dans les classes filles*/
		virtual double MATGet(unsigned int x, unsigned int y);
		//methodes
	public:
		/*type void à adapter dans les classes filles*/
		virtual void MATPrint(); //ou MATAfficher
		virtual CMatriceDouble& MATt(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATTransposee
		virtual CMatriceDouble& MATAdd(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATTransposee
		virtual CMatriceDouble& MATSub(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATSoustraction
		virtual CMatriceDouble& MATMult(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATMultiplication
		virtual CMatriceDouble& MATDiv(CMatrice* pMATarg) { return *new CMatriceDouble(); }; //ou MATDivision
};
