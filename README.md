# Projet de C++ - "Les matrices"
### *Sujet de Vincent T'Kindt - Polytech Tours*

**Etudiants :**
- Théo Boisseau (theo.boisseau@etu.univ-tours.fr)
- Sarah Denis (sarah.denis-2@etu.univ-tours.fr)

---
Commande(s) utile(s):

	cd ~/DI3ProjetMatrice/DI3ProjetMatrice/Debug
	g++ -o DI3ProjetMatrice ../source/DI3ProjetMatrice.cpp ../source/CException.cpp ../source/CFichier.cpp ../source/CMatrice.cpp ../source/CMatriceDouble.cpp ../source/CMatriceCaractere.cpp ../source/CMatriceEntier.cpp
	./DI3ProjetMatrice

	rm vgcore.*
	valgrind --leak-check=full ./DI3ProjetMatrice/Debug/DI3ProjetMatrice
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./DI3ProjetMatrice/Debug/DI3ProjetMatrice
