/*
 ---------------------------------------------------------------------------
Fichier          : tab.cpp
Auteur(s)        : Cédric Rosat - Tomas Pavoni
Date creation    : 08.12.2021

 Description     : Déclarations des fonctions de la librairie tab.h.

 Remarque(s)     :  Une matrice de vecteurs vides est considérée comme vide.
                    "En mathématiques, une matrice vide est définie comme une matrice
                    dont l'une des dimensions m ou n est nulle ; il s'agit donc de
                    matrices de dimensions m*0, 0*n ou bien 0*0"
                    https://fr.wikipedia.org/wiki/Matrice_vide

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

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

// Retourne un vecteur contenant la somme de chaque ligne
Vecteur addLignes(Vecteur vecteur, const Vecteur& v);

// Retourne un vecteur contenant la somme de chaque colonne
Vecteur addColonnes(Vecteur v1, Vecteur v2);

// Retourne true si le premier vecteur se situe avant le deuxième dans un ordre
// croissant
bool estAvant(const Vecteur& v1, const Vecteur& v2);

// Retourne true si la matrice est vide (voir remarques dans l'en-tête)
bool estMatriceVide(const Matrice& m);

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
	if (estMatriceVide(m)) {return true;}

	// Contrôle si la taille de chaque ligne == au nombre de lignes de la matrice
	return all_of(m.begin(), m.end(),
					  [m](const Vecteur& ligne){return ligne.size() == m.size();});
}

//-----------------------------------------------------------------------------
bool estReguliere(const Matrice& m) {
	// Une matrice vide est régulière
	if (estMatriceVide(m)) {return true;}

	// Contrôle si toutes les lignes ont la même taille que la première
	size_t taille = (*m.begin()).size();
	return all_of(m.begin() + 1, m.end(),
					  [taille](const Vecteur& ligne){return ligne.size() == taille;});
}

//-----------------------------------------------------------------------------
size_t minCol(const Matrice& m) {
	// La taille des colones d'une matrice vide est de 0
	if (estMatriceVide(m)) {return 0;}

	// Cherche le vecteur avec la plus petite taille et retourne celle-ci
	// return (*min_element(m.begin(), m.end(), estPlusPetit)).size();
	return (*min_element(m.begin(), m.end(), estPlusPetit)).size();
}

//-----------------------------------------------------------------------------
size_t maxCol(const Matrice& m) {
	// La taille des lignes d'une matrice vide est de 0
	if (estMatriceVide(m)) {return 0;}

	// Cherche le vecteur avec la plus grande taille et retourne celle-ci
   return (*max_element(m.begin(), m.end(), estPlusPetit)).size();
}

//-----------------------------------------------------------------------------
Vecteur sommeLigne(const Matrice& m) {
   // Si la matrice est vide, on retourne un vecteur vide
	if (estMatriceVide(m)) {return Vecteur {};}
   // Faire la somme de chaque ligne de la matrice et le rajouter dans le vecteur
   // vide
   return accumulate(m.begin(), m.end(), Vecteur{}, addLignes);
}

//-----------------------------------------------------------------------------
Vecteur sommeColonne(const Matrice& m) {
   // Si la matrice est vide, on retourne un vecteur vide
   if (m.empty()) {return Vecteur {};}
   // Faire la somme de chaque colonne de la matrice et le rajouter dans le vecteur
   // vide
   return accumulate(m.begin(), m.end(), Vecteur{}, addColonnes);
}

//-----------------------------------------------------------------------------
Vecteur vectSommeMin(const Matrice& m) {
	// Contient la somme des éléments de chaque ligne
	Vecteur v = sommeLigne(m);
	if (estMatriceVide(m)) {return v;}
	// Égale la capacité du vecteur au nombre de lignes de la matrice
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
Vecteur addLignes(Vecteur vecteur, const Vecteur& v) {
   vecteur.push_back(accumulate(v.begin(), v.end(), 0));
   return vecteur;
}

//-----------------------------------------------------------------------------
Vecteur addColonnes(Vecteur v1, Vecteur v2) {
   if(v1.size() < v2.size()) {
      v1.resize(v2.size());
   }
   transform(v2.begin(), v2.end(), v1.begin(), v1.begin(), std::plus<>());
   return v1;
}

//-----------------------------------------------------------------------------
bool estAvant(const Vecteur& v1, const Vecteur& v2) {
   return v1 < v2;
}

//-----------------------------------------------------------------------------
bool estMatriceVide(const Matrice& m) {
	// Une matrice avec aucun contenu est considérée comme vide
	if (m.empty()) {return true;}

	// Une matrice dont le contenu des lignes est vide est aussi considérée comme vide
	return all_of(m.begin(), m.end(), [](const Vecteur& v){return v.empty();});
}

//-----------------------------------------------------------------------------