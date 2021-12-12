/*
 ---------------------------------------------------------------------------
<<<<<<< Updated upstream
 Fichier         : tab.h
 Auteur(s)       : Cédric Rosat - Thomas Pavoni
 Date creation   : 08.12.2021
=======
Fichier         : tab.h
Auteur(s)       : Cédric Rosat - Tomas Pavoni
Date creation   : 08.12.2021
>>>>>>> Stashed changes

 Description     : -

 Remarque(s)     : -

 Modification(s) : -

 Compilateur     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#ifndef LABO07_MATRICE_TAB_H
#define LABO07_MATRICE_TAB_H

#include <vector>

using Type = int;
using Vecteur = std::vector<Type>;
using Matrice = std::vector<Vecteur>;

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
std::ostream& operator<<(std::ostream& os, const Vecteur& v);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
std::ostream& operator<<(std::ostream& os, const Matrice& m);

/**
 * nom         : estCarree
 *
 * description : Vérifie si la matrice @param m est carrée
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
bool estCarree(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
bool estReguliere(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
size_t minCol(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
size_t maxCol(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
Vecteur sommeLigne(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
Vecteur sommeColonne(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
Vecteur vectSommeMin(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
void shuffleMatrice(const Matrice& m);

/**
 * nom
 *
 * description
 *
 * @param
 * @param
 * @param
 *
 * return
 * /!\
 */
void sortMatrice(Matrice& m);


#endif //LABO07_MATRICE_TAB_H
