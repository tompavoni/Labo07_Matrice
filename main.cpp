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
		  << vecteur                                               << endl
		  << endl
		  << "Affiche des matrices au format [(..), (..), (..)] :" << endl
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

	cout << "===== Fonction minCol(...) ====="                         << endl
	     << "Retourne la longueur du plus petit vecteur de la matrice" << endl
	     << "Matrice : " << matrice                                    << endl
	     << "Longueur du plus petit vecteur : " << minCol(matrice)     << endl
		  << endl;

   // -------------------------------------------------------------------------
   // Test de la fonction maxCol
   // -------------------------------------------------------------------------

   cout << "===== Fonction maxCol(...) ====="                         << endl
	     << ""
        << "Matrice : " << matrice << endl
        << "Longueur du plus grand vecteur : "
        << maxCol(matrice) << endl << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction sommeLigne
	// -------------------------------------------------------------------------

	cout << "===== Fonction sommeLigne(...) ====="                    << endl
	     << "Retourne un vecteur contenant la somme de chaque ligne "
			  "de la matrice :"                                         << endl
	     << "Matrice : " << matrice                                   << endl
	     << "Somme des lignes : " << sommeLigne(matrice)              << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction sommeColonne
	// -------------------------------------------------------------------------

	cout << "===== Fonction sommeColonne(...) ====="                    << endl
	     << "Retourne un vecteur contenant la somme de chaque colonne "
			  "de la matrice :"                                           << endl
        << "Matrice : " << matrice                                     << endl
		  << "Somme des colonnes : " << sommeColonne(matrice)            << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction vectSommeMin
	// -------------------------------------------------------------------------

	cout << "===== Fonction vectSommeMin(...) ====="                          << endl
	     << "Retourne le vecteur de la matrice dont la somme des "
			  "elements de la ligne est la plus petite :"                       << endl
	     << "Matrice : " << matrice                                           << endl
	     << "Vecteur avec la plus petite somme : " << (vectSommeMin(matrice)) << endl
		  << endl;

   // -------------------------------------------------------------------------
   // Test de la fonction sortMatrice
   // -------------------------------------------------------------------------
   cout << "===== Fonction sortMatrice(...) ====="                 << endl
	     << "Trie dans l'ordre croissant en fonction de l'élément "
			  "min d'un vecteur"                                      << endl
        << "Matrice avant tri : " << matrice                       << endl;

   sortMatrice(matrice);

   cout << "Matrice triee : "     << matrice                       << endl
	     << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction shuffleMatrice
	// -------------------------------------------------------------------------

	cout << "===== Fonction shuffleMatrice(...) ====="                       << endl
	     << "Mélange les vecteurs de la matrice sans alterer les vecteurs :" << endl
		  << "Matrice avant shuffle : " << matrice                            << endl;

	shuffleMatrice(matrice);

	cout << "Matrice apres shuffle : " << matrice                            << endl
	     << endl
		  << "Trie a nouveau la matrice melangee : "                          << endl;

	sortMatrice(matrice);

	cout << "Matrice triee : "     << matrice                       << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Fin du programme
	// -------------------------------------------------------------------------

	finProgramme();
   return EXIT_SUCCESS;
}