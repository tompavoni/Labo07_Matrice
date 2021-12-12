/*
 ---------------------------------------------------------------------------
Fichier         : tab.cpp
Auteur(s)       : Cédric Rosat - Thomas Pavoni
Date creation   : 08.12.2021

Description     : -

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include <cstdlib>   //
#include <iostream>  // Affichage dans la console
#include <algorithm> //
#include <numeric>   //

#include "tab.h"

using namespace std;

bool plusPetit(const Vecteur& i, const Vecteur& j);

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
   return (*min_element(m.begin(), m.end(), plusPetit)).size();

}

//-----------------------------------------------------------------------------
Vecteur sommeLigne(const Matrice& m) {
   Vecteur v;
   for (Matrice::const_iterator ligne = m.begin(); ligne != m.end(); ligne++) {
      v.push_back(accumulate((*ligne).begin(), (*ligne).end(), 0));
   }
   //for_each(m.begin(), m.end(), v.push_back(accumulate()));
   return v;
}

//-----------------------------------------------------------------------------
Vecteur sommeColonne(const Matrice& m) {
   Vecteur v;

   /*for (Matrice::const_iterator ligne = m.begin(); ligne != m.end(); ligne++) {
      v.push_back(accumulate((*ligne).begin(), (*ligne).end(), 0));
   }
   */
   return v;

}

bool plusPetit(const Vecteur& i, const Vecteur& j) {
	return i.size() < j.size();
}