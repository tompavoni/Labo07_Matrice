/*
 ---------------------------------------------------------------------------
 Fichier         : main.cpp
 Auteur(s)       : Cédric Rosat - Thomas Pavoni
 Date creation   : 08.12.2021

 Description     : -

 Remarque(s)     : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <limits>

#include "annexe.h"
#include "tab.h"

using namespace std;

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
										 {1, 2, 1},
										 {2, 5, 7, 1},
										 {2, 2}};

	// -------------------------------------------------------------------------
	// Test de l'opérateur <<
	// -------------------------------------------------------------------------

	cout << "===== Operateur << ====="                            << endl
	     << "Affiche des vecteurs au format (v1, v2, ..., vn) :"  << endl
		  << vecteurVide                                           << endl
		  << vecteur                                               << endl
		  << endl
		  << "Affiche des matrices au format [(..), (..), (..)] :" << endl
		  << matriceVide                                           << endl
		  << matrice                                               << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction estCarree
	// -------------------------------------------------------------------------

	cout << "===== Fonction estCarree(...) ====="                   << endl
	     << "Indique si la matrice est carree :"                    << endl
		  << matriceReguliere << testMatriceCarree(matriceReguliere) << endl
		  << matriceCarree    << testMatriceCarree(matriceCarree)    << endl
		  << matriceVide      << testMatriceCarree(matriceVide)      << endl
		  << matrice          << testMatriceCarree(matrice)          << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction estReguliere
	// -------------------------------------------------------------------------

	cout << "===== Fonction estReguliere(...) ====="                   << endl
	     << "Indique si la matrice est reguliere :"                    << endl
	     << matriceReguliere << testMatriceReguliere(matriceReguliere) << endl
		  << matriceCarree    << testMatriceReguliere(matriceCarree)    << endl
		  << matriceVide      << testMatriceReguliere(matriceVide)      << endl
		  << matrice          << testMatriceReguliere(matrice)          << endl
	     << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction minCol
	// -------------------------------------------------------------------------

	cout << "===== Fonction minCol(...) =====" << endl
	     << "Matrice : " << matrice << endl
	     << "Longueur du plus petit vecteur de cette matrice : "
	     << minCol(matrice) << endl << endl;

   // -------------------------------------------------------------------------
   // Test de la fonction maxCol
   // -------------------------------------------------------------------------

   cout << "===== Fonction maxCol(...) =====" << endl
        << "Matrice : " << matrice << endl
        << "Longueur du plus grand vecteur de cette matrice : "
        << maxCol(matrice) << endl << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction sommeLigne
	// -------------------------------------------------------------------------

	cout << "===== Fonction sommeLigne(...) =====" << endl
	     << "Matrice : " << matrice << endl
	     << "Somme des éléments de chaque ligne de la matrice "
	     << sommeLigne(matrice) << endl << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction sommeColonne
	// -------------------------------------------------------------------------

	cout << "===== Fonction sommeColonne(...) =====" << endl
        << "Matrice : " << matrice << "Somme des colonnes : "
        << sommeColonne(matrice) << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction vectSommeMin
	// -------------------------------------------------------------------------

	cout << "===== Fonction vectSommeMin(...) =====" << endl
	     << "Matrice : " << matrice << endl
	     << "Vecteur dont la somme des elements est la plus petite : "
	     << (vectSommeMin(matrice)) << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction shuffleMatrice
	// -------------------------------------------------------------------------

   // -------------------------------------------------------------------------
   // Test de la fonction shuffleMatrice
   // -------------------------------------------------------------------------
   cout << "===== Fonction sortMatrice(...) =====" << endl
        << "Matrice : " << matrice << "Matrice triee : " << endl;

   sortMatrice(matrice);
   cout << matrice << endl;


   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}