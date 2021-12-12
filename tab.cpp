/*
 ---------------------------------------------------------------------------
Fichier          : tab.cpp
Auteur(s)        : Cédric Rosat - Tomas Pavoni
Date creation    : 08.12.2021

 Description     : Déclarations des fonctions de la librairie tab.h.

 Remarque(s)     : -

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include <cstdlib>   //
#include <iostream>  // ostream
#include <algorithm> // min_element, max_element, stable_sort, shuffle, all_of
#include <numeric>   // accumulate
#include <random>    // default_random_engine
#include <chrono>    // chrono::system_clock

#include "tab.h"

using namespace std;

//-----------------------------------------------------------------------------
// Fonctions internes à la librairie (prototypes)
//-----------------------------------------------------------------------------

// Retourne true si le premier vecteur est plus petit que le second
bool estPlusPetit(const Vecteur& v1, const Vecteur& v2);

//
Vecteur addLignes(Vecteur v_vide, const Vecteur& v);

// Retourne true si le premier vecteur se situe avant le deuxième dans un ordre
// croissant
bool estAvant(const Vecteur& v1, const Vecteur& v2);

//-----------------------------------------------------------------------------
// Fonctions publiques
//-----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Vecteur& v) {
   os << "(";
   for (Vecteur::const_iterator elem = v.begin(); elem != v.end(); ++elem) {
      if (elem != v.begin()) {os << ", ";} // Ajoute une virgule entre les valeurs
      os << *elem;
   }
   return os << ")";
}

//-----------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Matrice& m) {
   os << "[";
   for (Matrice::const_iterator ligne = m.begin(); ligne != m.end(); ++ligne) {
		if (ligne != m.begin()) {os << ", ";} // Ajoute une virgule entre les vecteurs
		os << *ligne;
	}
   return os << "]";
}

//-----------------------------------------------------------------------------
bool estCarree(const Matrice& m) {
	// Une matrice vide est carrée
	if (m.empty()) {return true;}

	// Contrôle si la taille de chaque ligne == au nombre de lignes de la matrice
	return all_of(m.begin(), m.end(),
					  [m](const Vecteur& ligne){return ligne.size() == m.size();});
}

//-----------------------------------------------------------------------------
bool estReguliere(const Matrice& m) {
	// Une matrice vide est régulière
	if (m.empty()) {return true;}

	// Contrôle si toutes les lignes ont la même taille que la première
	size_t taille = (*m.begin()).size();
	return all_of(m.begin() + 1, m.end(),
					  [taille](const Vecteur& ligne){return ligne.size() == taille;});
}

//-----------------------------------------------------------------------------
size_t minCol(const Matrice& m) {
	// Cherche le vecteur avec la plus petite taille et retourne celle-ci
   return (*min_element(m.begin(), m.end(), estPlusPetit)).size();
}

//-----------------------------------------------------------------------------
size_t maxCol(const Matrice& m) {
   // Cherche le vecteur avec la plus grande taille et retourne celle-ci
   return (*max_element(m.begin(), m.end(), estPlusPetit)).size();
}

//-----------------------------------------------------------------------------
Vecteur sommeLigne(const Matrice& m) {
   /*Vecteur v;
	v.reserve(m.size());
   // Faire la somme de chaque ligne de la matrice et le rajouter dans le vecteur v
   for (const auto& ligne : m) {
      v.push_back(accumulate(ligne.begin(), ligne.end(), 0));
   } */
   return accumulate(m.begin(), m.end(), Vecteur{}, addLignes);
}

//-----------------------------------------------------------------------------
Vecteur sommeColonne(const Matrice& m) {
   Vecteur v;
   size_t col = 0;
   // Faire la somme de chaque colonne de la matrice et le rajouter dans le vecteur v
   while (col != maxCol(m)) {
      int sommeCol = 0;
      for (const auto & ligne : m) {
         if (col >= ligne.size()) continue;// Si l'élément n'existe pas il est ignoré
         sommeCol += ligne.at(col);
      }
      v.push_back(sommeCol);
      col++;
   }
   return v;
}

//-----------------------------------------------------------------------------
Vecteur vectSommeMin(const Matrice& m) {
	// Contient la somme des éléments de chaque ligne
	Vecteur v = sommeLigne(m);
	v.reserve(m.size());

	// Calcule la position de l'élément dont la somme est la plus petite et
	// retourne le vecteur de la matrice se trouvant à cette position
	return m[(size_t) distance(v.begin(), min_element(v.begin(), v.end()))];
}

//-----------------------------------------------------------------------------
void shuffleMatrice(Matrice& m) {
	// Seed basée sur l'heure
	auto seed = (unsigned) chrono::system_clock::now().time_since_epoch().count();
	shuffle(m.begin(), m.end(), default_random_engine(seed));
}

//-----------------------------------------------------------------------------
void sortMatrice(Matrice& m) {
   // Tri basé sur l'ordre croissant des vecteurs
	stable_sort(m.begin(), m.end(), estAvant);
}

//-----------------------------------------------------------------------------
// Fonctions internes à la librairie
//-----------------------------------------------------------------------------
bool estPlusPetit(const Vecteur& v1, const Vecteur& v2) {
	return v1.size() < v2.size();
}

//-----------------------------------------------------------------------------
Vecteur addLignes(Vecteur v_vide, const Vecteur& v) {
   v_vide.push_back(accumulate(v.begin(), v.end(), 0));
   return v_vide;
}

//-----------------------------------------------------------------------------
bool estAvant(const Vecteur& v1, const Vecteur& v2) {
   return v1 < v2;
}