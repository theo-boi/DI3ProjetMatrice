#define CMATRICEH 0

class CMatrice {
	//attributs
	protected:
		unsigned int uiMATdimLigne;
		unsigned int uiMATdimColonne;
	//constructeurs et destructeurs
	//operateurs
	public:
		virtual CMatrice& operator=(float fConst)=0;
		virtual CMatrice& operator*(float fConst)=0;
		virtual CMatrice& operator/(float fConst)=0;
	//accesseurs
	public:
		/*type void a adapter dans les classes filles*/
		//virtual void MATGet(unsigned int x, unsigned int y)=0; //doit etre declaree dans la classe fille car void inextensible
	//methodes
	public:
		/*type void a adapter dans les classes filles*/
		virtual void MATPrint()=0; //ou MATAfficher
		virtual CMatrice& MATt(CMatrice* pMATarg)=0; //ou MATTransposee
		virtual CMatrice& MATAdd(CMatrice* pMATarg)=0; //ou MATTransposee
		virtual CMatrice& MATSub(CMatrice* pMATarg)=0; //ou MATSoustraction
		virtual CMatrice& MATMult(CMatrice* pMATarg)=0; //ou MATMultiplication
		virtual CMatrice& MATDiv(CMatrice* pMATarg)=0; //ou MATDivision
};
