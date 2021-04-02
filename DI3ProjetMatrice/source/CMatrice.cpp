#ifndef CMATRICEH
#define CMATRICEH 0
#include "../headers/CMatrice.h"
#endif 

class CMatrice {
	//attributs
	protected:
		unsigned int eMATdimLigne;
		unsigned int eMATdimColonne;
	//constructeurs et destructeurs
	//operateurs
	public:
		virtual void operator=(float fConst)=0;
		virtual void operator*(float fConst)=0;
		virtual void operator/(float fConst)=0;
	//accesseurs
	public:
		/*type void � adapter dans les classes filles*/
		virtual void MATGet(unsigned int x, unsigned int y)=0;
	//methodes
	public:
		/*type void � adapter dans les classes filles*/
		virtual void MATPrint(CMatrice* pMATarg)=0; //ou MATAfficher
		virtual void MATt(CMatrice* pMATarg)=0; //ou MATTransposee
		virtual void MATAdd(CMatrice* pMATarg)=0; //ou MATTransposee
		virtual void MATSub(CMatrice* pMATarg)=0; //ou MATSoustraction
		virtual void MATMult(CMatrice* pMATarg)=0; //ou MATMultiplication
		virtual void MATDiv(CMatrice* pMATarg)=0; //ou MATDivision
};