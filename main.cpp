/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.cpp
Auteur(s) : Tomas Pavoni
Date creation : <jj.mm.aaaa>
Description : <à compléter>
Remarque(s) : <à compléter>
Compilateur : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <limits>

#include "annexe.h"
#include "tab.h"

using namespace std;

void testMatriceReguliere(const Matrice& m) {
	cout << "La matrice suivante : " << m
	     << (estReguliere(m) ? " est reguliere" : " n'est pas reguliere") << endl;
}

void testMatriceCarree(const Matrice& m) {
	cout << "La matrice suivante : " << m
		  << (estCarree(m) ? " est carree" : " n'est pas carree") << endl;
}

int main() {
	// -------------------------------------------------------------------------
	// Vecteurs et matrices pour les tests de la librairie
	// -------------------------------------------------------------------------

   Vecteur vecteur          =  {1, 1, 3},
	        vecteurVide      =  {};

   Matrice matriceReguliere = {{1, 2, 3},
								       {4, 5, 6}},
	        matriceCarree    = {{1, 2, 3},
										 {4, 5, 6},
								       {7, 8, 9}},
	        matriceVide      = {},
	        matrice          = {{1, 2, 3},
										 {1, 3},
								       {6, 7, 8, 9}};

	cout << "Taille la plus petit de " << matrice << " = " << minCol(matrice) << endl;

	// -------------------------------------------------------------------------
	// Test de l'opérateur <<
	// -------------------------------------------------------------------------

	cout << "Affiche des vecteurs : " << endl
	     << vecteur                   << endl
		  << vecteurVide << endl       << endl
		  << "Affiche des matrices : " << endl
		  << matrice                   << endl
		  << matriceVide << endl       << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction estCarree
	// -------------------------------------------------------------------------

	cout << "Indique si la matrice est carree : " << endl;
	testMatriceCarree(matriceReguliere);
	testMatriceCarree(matriceCarree);
	testMatriceCarree(matriceVide);
	testMatriceCarree(matrice);
	cout << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction estReguliere
	// -------------------------------------------------------------------------

	cout << "Indique si la matrice est reguliere : " << endl;
	testMatriceReguliere(matriceReguliere);
	testMatriceReguliere(matriceCarree);
	testMatriceReguliere(matriceVide);
	testMatriceReguliere(matrice);
	cout << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction minCol
	// -------------------------------------------------------------------------

	// -------------------------------------------------------------------------
	// Test de la fonction sommeLigne
	// -------------------------------------------------------------------------

	// -------------------------------------------------------------------------
	// Test de la fonction sommeColonne
	// -------------------------------------------------------------------------

	// -------------------------------------------------------------------------
	// Test de la fonction vectSommeMin
	// -------------------------------------------------------------------------

	// -------------------------------------------------------------------------
	// Test de la fonction shuffleMatrice
	// -------------------------------------------------------------------------

   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}