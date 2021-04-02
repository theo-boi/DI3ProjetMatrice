class CMatrice {
	//attributs
	protected:
		unsigned int eMATdimLigne;
		unsigned int eMATdimColonne;
	//constructeurs et destructeurs
	//operateurs
	public:
		virtual CMatrice& operator=(float fConst)=0;
		virtual CMatrice& operator*(float fConst)=0;
		virtual CMatrice& operator/(float fConst)=0;
	//accesseurs
	public:
		/*type void à adapter dans les classes filles*/
		virtual void MATGet(unsigned int x, unsigned int y)=0;
	//methodes
	public:
		/*type void à adapter dans les classes filles*/
		virtual void MATPrint(CMatrice* pMATarg)=0; //ou MATAfficher
		virtual CMatrice& MATt(CMatrice* pMATarg)=0; //ou MATTransposee
		virtual CMatrice& MATAdd(CMatrice* pMATarg)=0; //ou MATTransposee
		virtual CMatrice& MATSub(CMatrice* pMATarg)=0; //ou MATSoustraction
		virtual CMatrice& MATMult(CMatrice* pMATarg)=0; //ou MATMultiplication
		virtual CMatrice& MATDiv(CMatrice* pMATarg)=0; //ou MATDivision
};