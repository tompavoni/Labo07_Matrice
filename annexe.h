/*
 ---------------------------------------------------------------------------
 Fichier         : annexe.h
 Auteur(s)       : Cédric Rosat - Tomas Pavoni
 Date creation   : 08.12.2021

 Description     : Initialisations de fonctions annexes utiles à la réalisation du
                   labo07.

 Remarque(s)     : -

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#ifndef LABO07_MATRICE_ANNEXE_H
#define LABO07_MATRICE_ANNEXE_H

#include <string>

#include "tab.h" // Matrice

/**
 * nom         : viderBuffer
 *
 * description : Vide le buffer
 *
 * return      : -
 */
void viderBuffer();

/**
 * nom         : finProgramme
 *
 * description : Termine le programme
 *
 * return      : -
 */
void finProgramme();

/**
 * nom         : testMatriceReguliere
 *
 * description : Affiche si une matrice est régulière ou non
 *
 * @param m    : La matrice à tester
 *
 * return      : string : "est reguliere" ou "n'est pas reguliere"
 */
std::string testMatriceReguliere(const Matrice& m);

/**
 * nom         : testMatriceCarree
 *
 * description : Affiche si une matrice est carrée ou non
 *
 * @param m    : La matrice à tester
 *
 * return      : string : "est carree" ou "n'est pas carree"
 */
std::string testMatriceCarree(const Matrice& m);

#endif //LABO07_MATRICE_ANNEXE_H
