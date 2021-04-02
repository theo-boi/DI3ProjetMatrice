#ifndef CMATRICEH
#define CMATRICEH 0
#include "CMatrice.h"
#endif 

class CMatriceDouble : public CMatrice {
	//atributs
	private:
		double** ppeMAIElem;
	//constructeurs et destructeurs
	public:
		CMatriceDouble() {};
		CMatriceDouble(CMatriceDouble& MADArg) {};
		~CMatriceDouble() {};
	//operateurs
	public:
		virtual CMatriceDouble& operator=(float fConst) {};
		virtual CMatriceDouble& operator*(float fConst) {};
		virtual CMatriceDouble& operator/(float fConst) {};
		//accesseurs
	public:
		/*type void à adapter dans les classes filles*/
		virtual void MATGet(unsigned int x, unsigned int y) {};
		//methodes
	public:
		/*type void à adapter dans les classes filles*/
		virtual void MATPrint(CMatrice* pMATarg) {}; //ou MATAfficher
		virtual CMatriceDouble& MATt(CMatrice* pMATarg) {}; //ou MATTransposee
		virtual CMatriceDouble& MATAdd(CMatrice* pMATarg) {}; //ou MATTransposee
		virtual CMatriceDouble& MATSub(CMatrice* pMATarg) {}; //ou MATSoustraction
		virtual CMatriceDouble& MATMult(CMatrice* pMATarg) {}; //ou MATMultiplication
		virtual CMatriceDouble& MATDiv(CMatrice* pMATarg) {}; //ou MATDivision
};

