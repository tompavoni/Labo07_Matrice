/*
 ---------------------------------------------------------------------------
 Fichier         : main.cpp
 Auteur(s)       : Cédric Rosat - Tomas Pavoni
 Date creation   : 08.12.2021

<<<<<<< Updated upstream
 Description     : Ce programme nous permet de tester le bon fonctionnement de toutes
                   les fonctions de la libraire tab.h.
                   2 vecteurs et 4 matrices sont initialisés afin de pouvoir
                   tester le maximum de cas possibles.
                   Une fois le programme lancé, tous les résultats des tests
                   s'afficheront sur la console.
=======
 Description     : Programme de test pour la librairie tab.cpp
>>>>>>> Stashed changes

 Remarque(s)     : Aucune valeur n'a besoin d'être saisie par l'utilisateur.
                   Une matrice vide est réputée être carrée et régulière.
                   Les éléments absents (matrice irrégulière) sont simplement
                   ignorés.

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream> // Affichage console

#include "tab.h"    // Manipulation vecteurs/matrices
#include "annexe.h"

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
		     matriceVectVide  = {{}, {}, {}},
	        matrice          = {{1, 2, 3},
										 {1, 2, 1},
										 {2, 5, 7, 1},
										 {2, 2},
										 {}};

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
	     << "Matrice : "                        << matrice             << endl
	     << "Longueur du plus petit vecteur : " << minCol(matrice)     << endl
		  << "Matrice : "                        << matriceVide         << endl
		  << "Longueur du plus petit vecteur : " << minCol(matriceVide) << endl
		  << endl;

   // -------------------------------------------------------------------------
   // Test de la fonction maxCol
   // -------------------------------------------------------------------------

   cout << "===== Fonction maxCol(...) ====="                         << endl
	     << ""
        << "Matrice : " << matrice << endl
        << "Longueur du plus grand vecteur : "
        << maxCol(matrice) << endl << endl;

	cout << "===== Fonction maxCol(...) ====="                         << endl
		  << "Retourne la longueur du plus grand vecteur de la matrice" << endl
		  << "Matrice : "                        << matrice             << endl
		  << "Longueur du plus grand vecteur : " << maxCol(matrice)     << endl
		  << "Matrice : "                        << matriceVide         << endl
		  << "Longueur du plus grand vecteur : " << maxCol(matriceVide) << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction sommeLigne
	// -------------------------------------------------------------------------

	cout << "===== Fonction sommeLigne(...) ====="                    << endl
	     << "Retourne un vecteur contenant la somme de chaque ligne "
			  "de la matrice :"                                         << endl
	     << "Matrice : "          << matrice                          << endl
	     << "Somme des lignes : " << sommeLigne(matrice)              << endl
		  << "Matrice : "          << matriceVide                      << endl
		  << "Somme des lignes : " << sommeLigne(matriceVide)          << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction sommeColonne
	// -------------------------------------------------------------------------

	cout << "===== Fonction sommeColonne(...) ====="                    << endl
	     << "Retourne un vecteur contenant la somme de chaque colonne "
			  "de la matrice :"                                           << endl
        << "Matrice : "            << matrice                          << endl
		  << "Somme des colonnes : " << sommeColonne(matrice)            << endl
		  << "Matrice : "            << matriceVide                      << endl
		  << "Somme des colonnes : " << sommeColonne(matriceVide)        << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction vectSommeMin
	// -------------------------------------------------------------------------

	cout << "===== Fonction vectSommeMin(...) ====="                     << endl
	     << "Retourne le vecteur de la matrice dont la somme des "
			  "elements de la ligne est la plus petite :"                  << endl
	     << "Matrice : "                  << matrice                     << endl
	     << "Vecteur (somme minimale) : " << (vectSommeMin(matrice))     << endl
		  << "Matrice : "                  << matriceVide                 << endl
		  << "Vecteur (somme minimale) : " << (vectSommeMin(matriceVide)) << endl
		  << endl;

   // -------------------------------------------------------------------------
   // Test de la fonction sortMatrice
   // -------------------------------------------------------------------------
   cout << "===== Fonction sortMatrice(...) ====="                 << endl
	     << "Trie dans l'ordre croissant en fonction de l'élément "
			  "min d'un vecteur"                                      << endl
        << "Matrice 1 avant tri : " << matrice                     << endl
		  << "Matrice 2 avant tri : " << matriceVide                 << endl;

   sortMatrice(matrice);
	sortMatrice(matriceVide); // Teste le fonctionnement avec une matrice vide

   cout << "Matrice 1 apres tri : " << matrice     << endl
	     << "Matrice 2 apres tri : " << matriceVide << endl
	     << endl;

	// -------------------------------------------------------------------------
	// Test de la fonction shuffleMatrice
	// -------------------------------------------------------------------------

	cout << "===== Fonction shuffleMatrice(...) ====="                       << endl
	     << "Mélange les vecteurs de la matrice sans alterer les vecteurs :" << endl
		  << "Matrice 1 avant shuffle : " << matrice                          << endl
		  << "Matrice 2 avant shuffle : " << matriceVide                      << endl;

	shuffleMatrice(matrice);
	shuffleMatrice(matriceVide); // Teste le fonctionnement avec une matrice vide

	cout << "Matrice 1 apres shuffle : " << matrice        << endl
	     << "Matrice 2 apres shuffle : " << matriceVide    << endl
	     << endl
		  << "Trie a nouveau la matrice 1 melangee : "      << endl;

	sortMatrice(matrice);

	cout << "Matrice 1 triee : " << matrice << endl
		  << endl;

	// -------------------------------------------------------------------------
	// Fin du programme
	// -------------------------------------------------------------------------

	//finProgramme();
   return EXIT_SUCCESS;
}