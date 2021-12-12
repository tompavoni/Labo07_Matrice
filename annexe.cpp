/*
 ---------------------------------------------------------------------------
 Fichier         : annexe.cpp
 Auteur(s)       : Cédric Rosat - Thomas Pavoni
 Date creation   : 08.12.2021

 Description     : Déclarations des fonctions de la librairie annexe.h.

 Remarque(s)     : -

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include <iostream> // Affichage console
#include <limits>   // Vider buffer

#include "annexe.h"

using namespace std;

void viderBuffer() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void finProgramme() {
	cout << "Veuillez presser ENTREE pour quitter le programme...";
	viderBuffer();
}

string testMatriceReguliere(const Matrice& m) {
	return estReguliere(m) ? " est reguliere" : " n'est pas reguliere";
}

string testMatriceCarree(const Matrice& m) {
	return estCarree(m) ? " est carree" : " n'est pas carree";
}