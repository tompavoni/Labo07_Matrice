/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.cpp
Auteur(s) : Tomas Pavoni
Date creation : <jj.mm.aaaa>
Description : <à compléter>
Remarque(s) : <à compléter>
Compilateur : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <limits>

#include "annexe.h"
#include "tab.h"

using namespace std;

int main() {

   Vecteur v = {1, 1, 3};
   Matrice m = {v, v, v};

   cout << v << endl;
   cout << m << endl;

   cout << estReguliere(m);

   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}