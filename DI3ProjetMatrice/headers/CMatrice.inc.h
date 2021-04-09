#ifndef CMATRICEH
#include "CMatrice.h"
#endif

/*** Constructeurs et destructeurs ***/

template<class T>
CMatrice<T>::CMatrice() {
	ppdMATelem = nullptr;
}

template<class T>
CMatrice<T>::CMatrice(const CMatrice<T>& MAT2arg) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (const T) MAT2arg.MATgetElem(0,0); }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	uiMATdimLigne = MAT2arg.MATgetDimLigne();
	uiMATdimColonne = MAT2arg.MATgetDimColonne();

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MAT2arg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = (const T) MAT2arg.MATgetElem(uiBoucleForX, uiBoucleForY);
		}
	}
}

template<class T>
CMatrice<T>::CMatrice(const unsigned int uiX, const unsigned int uiY) {
	//init
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = T(); //on initialise chaque element par sa valeur d'initialisation
		}
	}
}

template<class T> template<class T2>
CMatrice<T>::CMatrice(const unsigned int uiX, const unsigned int uiY, T2 T2elem) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (const T) T2elem; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("MATsetElem (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	uiMATdimLigne = uiX;
	uiMATdimColonne = uiY;

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//initialisation de chaque element a 1 par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = (const T) T2elem; //on initialise chaque element par sa valeur d'initialisation
		}
	}
}


template<class T>
CMatrice<T>::~CMatrice() {
	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMATelem[uiBoucleFor];
	delete[] ppdMATelem;
}


/*** Accesseurs et mutateurs ***/

template<class T>
T CMatrice<T>::MATgetElem(const unsigned int uiArgX, const unsigned int uiArgY) const throw(CException) {
	//Leve l'exception de conversion si uiArgX ou uiArgY sont trop grands
	if (uiArgX >= uiMATdimLigne || uiArgY >= uiMATdimColonne) {
		CException EXCdimension;
		EXCdimension.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCdimension.EXCSetCommentaire("MATgetElem (valeurs des arguments incoherents)");
		throw(EXCdimension);
	}

	return ppdMATelem[uiArgX][uiArgY];
}

template<class T> template<class T2>
void CMatrice<T>::MATsetElem(const unsigned int uiArgX, const unsigned int uiArgY, T2 T2elem) throw(CException) {
	//Leve l'exception de conversion si type trop different
	try { (const T) T2elem; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("MATsetElem (type de l'argument incompatible)");
		throw(EXCconversion);
	}
	//Effectuer un try pour lever les erreurs de conversion si uiX ou uiY sont trop grands
	if (uiArgX >= uiMATdimLigne || uiArgY >= uiMATdimColonne) {
		CException EXCdimension;
		EXCdimension.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCdimension.EXCSetCommentaire("MATsetElem (valeurs des arguments incoherents)");
		throw(EXCdimension);
	}

	//set
	ppdMATelem[uiArgX][uiArgY] = (const T) T2elem;
}


/*** Operateurs ***/

template<class T>
CMatrice<T>& CMatrice<T>::operator=(const CMatrice<T>& MAT2arg) throw(CException) {
	//Leve une exception de conversion si type trop different
	try { (const T) MAT2arg.MATgetElem(0, 0); }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("Constructeur de recopie (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//liberation de chaque ligne de la memoire
	for (unsigned int uiBoucleFor = 0; uiBoucleFor < uiMATdimLigne; uiBoucleFor++)
		delete[] ppdMATelem[uiBoucleFor];
	delete[] ppdMATelem;

	//init
	uiMATdimLigne = MAT2arg.MATgetDimLigne();
	uiMATdimColonne = MAT2arg.MATgetDimColonne();

	//allocation dynamique de chaque ligne
	ppdMATelem = new T*[uiMATdimLigne];
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de MATarg par colonne (par ligne)
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			ppdMATelem[uiBoucleForX][uiBoucleForY] = (const T) MAT2arg.MATgetElem(uiBoucleForX, uiBoucleForY);
		}
	}

	return *this; //passage par reference
}

template<class T> template<class T2>
CMatrice<T> CMatrice<T>::operator*(const T2 T2arg) const throw(CException) {
	//Leve une exception de conversion si type trop different
	try { (const T) T2arg; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("operator* (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	CMatrice<T> MATmult;
	MATmult.uiMATdimLigne = uiMATdimLigne;
	MATmult.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MATmult.ppdMATelem = new T*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MATmult.ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat de la multiplication de chaque element par cfConst pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MATmult.ppdMATelem[uiBoucleForX][uiBoucleForY] = ppdMATelem[uiBoucleForX][uiBoucleForY] * (const T) T2arg;
		}
	}
	return MATmult; //passage par valeur : MATmult est recopie
}

template<class T, class T2>
CMatrice<T> operator*(const T2 T2arg, const CMatrice<T> MAT2arg) throw(CException) {
	//Leve une exception de conversion si type trop different
	try { (const T) T2arg; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("operator* (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	CMatrice<T> MATmult = CMatrice<T>(MAT2arg);

	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MATmult.MATgetDimLigne(); uiBoucleForX++) {
		//calcul de chaque element par vecteur
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MATmult.MATgetDimColonne(); uiBoucleForY++) {
			MATmult.MATsetElem(uiBoucleForX, uiBoucleForY, MATmult.MATgetElem(uiBoucleForX, uiBoucleForY) * (const T) T2arg);
		}
	}
	return MATmult; //passage par valeur : MATmult est recopie
}

template<class T> template<class T2>
CMatrice<T> CMatrice<T>::operator/(const T2 T2arg) const throw(CException) {
	//Leve une exception de conversion si type trop different
	try { (const T) T2arg; }
	catch (CException EXCLevee) { EXCLevee.EXCGestionaireException(); }
	catch (...) {
		CException EXCconversion;
		EXCconversion.EXCSetId(types_incompatibles); //erreur de type 1
		EXCconversion.EXCSetCommentaire("operator/ (type de l'argument incompatible)");
		throw(EXCconversion);
	}

	//init
	CMatrice<T> MATdiv;
	MATdiv.uiMATdimLigne = uiMATdimLigne;
	MATdiv.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MATdiv.ppdMATelem = new T*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MATdiv.ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat de la division de chaque element par cfConst pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MATdiv.ppdMATelem[uiBoucleForX][uiBoucleForY] = ppdMATelem[uiBoucleForX][uiBoucleForY] / T2arg;
		}
	}
	return MATdiv; //passage par valeur : MATdiv est recopie
}

template<class T> template<class T2>
CMatrice<T> CMatrice<T>::operator+(const CMatrice<T2>& MAT2arg) const throw(CException) {
	//Leve une exception en cas de dimensions incompatibles entre MADActuelle et MATarg
	if (uiMATdimLigne != MAT2arg.uiMATdimLigne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator+ (nombre de LIGNES de l'argument incoherent)");
		throw(EXCconversion);
	}
	if (uiMATdimColonne != MAT2arg.uiMATdimColonne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator+ (nombre de COLONNES de l'argument incoherent)");
		throw(EXCconversion);
	}

	//init
	CMatrice<T> MATadd;
	MATadd.uiMATdimLigne = uiMATdimLigne;
	MATadd.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MATadd.ppdMATelem = new T*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MATadd.ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat pour chaque element de sa somme avec celui aux memes coordonnees dans MAT2arg, pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MATadd.ppdMATelem[uiBoucleForX][uiBoucleForY] = ppdMATelem[uiBoucleForX][uiBoucleForY] + MAT2arg.ppdMATelem[uiBoucleForX][uiBoucleForY];
		}
	}
	return MATadd; //passage par valeur : MATadd est recopie
}

template<class T> template<class T2>
CMatrice<T> CMatrice<T>::operator-(const CMatrice<T2>& MAT2arg) const throw(CException) {
	//Leve une exception en cas de dimensions incompatibles entre MADActuelle et MATarg
	if (uiMATdimLigne != MAT2arg.uiMATdimLigne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator- (nombre de LIGNES de l'argument incoherent)");
		throw(EXCconversion);
	}
	if (uiMATdimColonne != MAT2arg.uiMATdimColonne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator- (nombre de COLONNES de l'argument incoherent)");
		throw(EXCconversion);
	}

	//init
	CMatrice<T> MATsous;
	MATsous.uiMATdimLigne = uiMATdimLigne;
	MATsous.uiMATdimColonne = uiMATdimColonne;

	//calcul
	MATsous.ppdMATelem = new T*[uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		MATsous.ppdMATelem[uiBoucleForX] = new T[uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie le resultat pour chaque element de sa soustraction par celui aux memes coordonnees dans MAT2arg, pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) {
			MATsous.ppdMATelem[uiBoucleForX][uiBoucleForY] = ppdMATelem[uiBoucleForX][uiBoucleForY] - MAT2arg.ppdMATelem[uiBoucleForX][uiBoucleForY];
		}
	}
	return MATsous; //passage par valeur : MATsous est recopie
}

template<class T> template<class T2>
CMatrice<T> CMatrice<T>::operator*(const CMatrice<T2>& MAT2arg) const throw(CException) {
	//Leve une exception en cas de dimensions incompatibles entre MADActuelle et MATarg
	if (uiMATdimColonne != MAT2arg.uiMATdimLigne) {
		CException EXCconversion;
		EXCconversion.EXCSetId(dimensions_incompatibles); //erreur de type 2
		EXCconversion.EXCSetCommentaire("operator* (nombre de LIGNES de l'argument incoherent)");
		throw(EXCconversion);
	}
	//Le produit de MAD1 et MAD2 est possible <=> MAD1 est de dimensions NxR et MAD2 est de dimensions RxM. Le produit est alors de taille  MxN.

	//init
	CMatrice<T> MATmult;
	MATmult.uiMATdimLigne = uiMATdimLigne;
	MATmult.uiMATdimColonne = MAT2arg.uiMATdimColonne;

	//calcul
	MATmult.ppdMATelem = new T*[MATmult.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MATmult.uiMATdimLigne; uiBoucleForX++) {
		MATmult.ppdMATelem[uiBoucleForX] = new T[MATmult.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		/*
		 *	Chaque element de coordonnees (x,y) de la matrice de resultat MATmult est egal
		 *	au produit scalaire de la uiBoucleForX-ieme ligne de MADActuelle par la uiBoucleForY-ieme colonne de MAT2arg
		 */
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MATmult.uiMATdimColonne; uiBoucleForY++) {

			//pour chaque ligne de MADActuelle
			T dSommeProdScalaireVects = 0;
			//on parcourt la ligne de MADActuelle (soit aussi la colonne de MAT2arg)
			for (unsigned int uiBoucleForYCalcul = 0; uiBoucleForYCalcul < uiMATdimColonne; uiBoucleForYCalcul++) {
				//on somme le produit de chaque uiBoucleForYCalcul-ieme element
				dSommeProdScalaireVects += ppdMATelem[uiBoucleForX][uiBoucleForYCalcul] * MAT2arg.ppdMATelem[uiBoucleForYCalcul][uiBoucleForY];
			}
			MATmult.ppdMATelem[uiBoucleForX][uiBoucleForY] = dSommeProdScalaireVects;

		}
	}
	return MATmult; //passage par valeur : MATmult est recopie
}


/*** Autres methodes ***/

template<class T>
void CMatrice<T>::MATprint(const bool bEndl) const {
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < uiMATdimLigne; uiBoucleForX++) {
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < uiMATdimColonne; uiBoucleForY++) { //affiche les uiMATdimLigne elements de la uiBoucleForX-ieme ligne
			std::cout << ppdMATelem[uiBoucleForX][uiBoucleForY];
			if (uiBoucleForY < uiMATdimColonne) //met un espace seulement entre des elements
				std::cout << "\t";
		}
		if (uiBoucleForX != uiMATdimLigne - 1)
			std::cout << std::endl << std::endl; //saute une ligne seulement entre des elements
	}
	std::cout << std::endl;
	if (bEndl) std::cout << std::endl << std::endl; //revient une 2e fois a la ligne seulement si bEndl est vrai
}

template<class T>
CMatrice<T> CMatrice<T>::MATt() const {
	//init
	CMatrice<T> MATt;
	/*
	 *	Chaque element de coordonnees (x,y) prend la valeur de celui dans MATt de coordonnees (y,x).
	 *	Les dimensions de la matrice sont donc logiquement inversees.
	 */
	MATt.uiMATdimLigne = uiMATdimColonne;
	MATt.uiMATdimColonne = uiMATdimLigne;

	//calcul
	MATt.ppdMATelem = new T*[MATt.uiMATdimLigne]; //allocation dynamique de chaque ligne
	for (unsigned int uiBoucleForX = 0; uiBoucleForX < MATt.uiMATdimLigne; uiBoucleForX++) {
		MATt.ppdMATelem[uiBoucleForX] = new T[MATt.uiMATdimColonne]; //allocation dynamique du contenu de chaque colonne (par ligne)
		//recopie chaque element de coordonnees (uiBoucleForY,uiBoucleForX) a (uiBoucleForX,uiBoucleForY) pour chaque colonne
		for (unsigned int uiBoucleForY = 0; uiBoucleForY < MATt.uiMATdimColonne; uiBoucleForY++) {
			MATt.ppdMATelem[uiBoucleForX][uiBoucleForY] = ppdMATelem[uiBoucleForY][uiBoucleForX];
		}
	}
	return MATt;
}