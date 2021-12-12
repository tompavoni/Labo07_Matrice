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

//-----------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Vecteur& v) {
   os << "(";
   for (Vecteur::const_iterator elem = v.begin(); elem != v.end(); ++elem) {
      if (elem != v.begin())
         os << ", "; // Ajoute un séparateur entre les valeurs
      os << *elem;
   }
   os << ")";

   return os;
}

//-----------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Matrice& m) {
   os << "[";
   for (Matrice::const_iterator ligne = m.begin(); ligne != m.end(); ++ligne) {
      if (ligne != m.begin())
         os << ", "; // Ajoute un séparateur entre les vecteurs
      os << *ligne;
   }
   os << "]";

   return os;
}

//-----------------------------------------------------------------------------
bool estCarree() {

}

//-----------------------------------------------------------------------------
bool estReguliere(const Matrice& m) {
   size_t taille = (*m.begin()).size(); // Taille du premier vecteur

   return all_of(m.begin() + 1, m.end(),
                 [taille](Vecteur v){return taille == v.size();});
}

//-----------------------------------------------------------------------------
unsigned minCol(const Matrice& m) {
   Vecteur v;
   for (Matrice::const_iterator ligne = m.begin(); ligne != m.end(); ligne++) {
      v.push_back((*ligne).size());
   }

   return *min_element(v.begin(), v.end());

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