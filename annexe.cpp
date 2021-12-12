/*
 ---------------------------------------------------------------------------
 Fichier         : annexe.cpp
 Auteur(s)       : Cédric Rosat - Thomas Pavoni
 Date creation   : 08.12.2021

 Description     : -

 Remarque(s)     : -

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include "annexe.h"

using namespace std;

string testMatriceReguliere(const Matrice& m) {
	return estReguliere(m) ? " est reguliere" : " n'est pas reguliere";
}

string testMatriceCarree(const Matrice& m) {
	return estCarree(m) ? " est carree" : " n'est pas carree";
}