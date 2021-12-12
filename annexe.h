/*
 ---------------------------------------------------------------------------
 Fichier         : annexe.h
 Auteur(s)       : Cédric Rosat - Thomas Pavoni
 Date creation   : 08.12.2021

 Description     : -

 Remarque(s)     : -

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#ifndef LABO07_MATRICE_ANNEXE_H
#define LABO07_MATRICE_ANNEXE_H

#include <string>
#include "tab.h"

void viderBuffer();

void finProgramme();

std::string testMatriceReguliere(const Matrice& m);

std::string testMatriceCarree(const Matrice& m);

#endif //LABO07_MATRICE_ANNEXE_H
