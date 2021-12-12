/*
 ---------------------------------------------------------------------------
Fichier          : tab.h
Auteur(s)        : Cédric Rosat - Tomas Pavoni
Date creation    : 08.12.2021

 Description     : Initialisations de fonctions utiles à la manipulation de
                   vecteurs et de matrices.

 Remarque(s)     : Fichier en lien avec le labo07.
                   Une matrice de vecteurs vides est considérée comme vide.
                   "En mathématiques, une matrice vide est définie comme une matrice
                    dont l'une des dimensions m ou n est nulle ; il s'agit donc de
                    matrices de dimensions m*0, 0*n ou bien 0*0"
                    https://fr.wikipedia.org/wiki/Matrice_vide

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#ifndef LABO07_MATRICE_TAB_H
#define LABO07_MATRICE_TAB_H

#include <vector> // Type Vecteur

using Type = int;
using Vecteur = std::vector<Type>;
using Matrice = std::vector<Vecteur>;

/**
 * @overload
 * nom         : operator<<
 *
 * description : Affiche un Vecteur au format (v1, v2, …, vn)
 *
 * @param os   : Le flux de sortie
 * @param v    : Le vecteur à afficher
 *
 * return      : Le flux de sortie
 */
std::ostream& operator<<(std::ostream& os, const Vecteur& v);

/**
 * @overload
 * nom         : operator<<
 *
 * description : Affiche une Matrice au format [(..),(..),(..)]
 *
 * @param os   : Le flux de sortie
 * @param m    : La matrice à afficher
 *
 * return      : Le flux de sortie
 */
std::ostream& operator<<(std::ostream& os, const Matrice& m);

/**
 * nom         : estCarree
 *
 * description : Vérifie si la matrice @param m est carrée
 *
 * @param m    : La matrice à verifier
 *
 * return      : Un booléen : 1 si carrée, 0 si pas carrée
 *
 * /!\         : Une matrice vide est carrée
 */
bool estCarree(const Matrice& m);

/**
 * nom         : estReguliere
 *
 * description : Vérifie si la matrice @param m est régulière
 *
 * @param m    : La matrice à verifier
 *
 * return      : Un booléen : 1 si régulière, 0 si pas régulière
 *
 * /!\         : Une matrice vide est régulière
 */
bool estReguliere(const Matrice& m);

/**
 * nom         : minCol
 *
 * description : Retourne la longueur minimale des vecteurs d’une matrice
 *
 * @param m    : La matrice à manipuler
 *
 * return
 * /!\
 */
size_t minCol(const Matrice& m);

/**
 * nom         : maxCol
 *
 * description : Retourne la longueur maximale des vecteurs d’une matrice
 *
 * @param m    : La matrice à manipuler
 *
 * return
 * /!\
 */
size_t maxCol(const Matrice& m);

/**
 * nom         : sommeLigne
 *
 * description : Retourne un vecteur contenant la somme des valeurs de chacune des
 *               lignes
 *
 * @param m    : La matrice à manipuler
 *
 * return      : Un vecteur contenant la somme des valeurs de chacune des
 *               lignes
 */
Vecteur sommeLigne(const Matrice& m);

/**
 * nom         : sommeColonne
 *
 * description : Retourne un vecteur contenant la somme des valeurs dechacune des
 *               colonnes
 *
 * @param m    : La matrice à manipuler
 *
 * return      : Un vecteur contenant la somme des valeurs de chacune des
 *               colonnes
 *
 * /!\         : Les éléments absents (matrice irrégulière) sont simplement ignorés
 */
Vecteur sommeColonne(const Matrice& m);

/**
 * nom         : vectSommeMin
 *
 * description : Retourne le vecteur d’une matrice dont la somme des valeurs est la
 *               plus faible
 *
 * @param m    : La matrice à manipuler
 *
 * return      : Le vecteur d’une matrice dont la somme des valeurs est la
 *               plus faible
 *
 * /!\         : Si plusieurs vecteurs présentent la même somme, la fonction
 *               retourne celui d’indice le plus faible
 */
Vecteur vectSommeMin(const Matrice& m);

/**
 * nom         : shuffleMatrice
 *
 * description : Mélange les vecteurs d’une matrice sans altérer les vecteurs
 *
 * @param m    : La matrice à manipuler
 *
 * return      : -
 *
 * /!\         : La seed du générateur est basée sur l’heure
 */
void shuffleMatrice(Matrice& m);

/**
 * nom         : sortMatrice
 *
 * description : Trier dans l’ordre croissant une matrice en fonction de l’élément
 *               min d’un vecteur
 *
 * @param m    : La matrice à manipuler
 *
 * return      : -
 */
void sortMatrice(Matrice& m);


#endif //LABO07_MATRICE_TAB_H
