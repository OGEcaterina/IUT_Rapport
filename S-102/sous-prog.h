#ifndef SOUSPROG_H
#define SOUSPROG_H
#include <vector>
#include "carte.h"
#include "joueur.h"
#include "jeu.h"

using namespace std;

//range les cartes en fonction de l'attaque croissante
void RangerAtta(vector <Carte>& pile);
//affecte un rang en fonction de l'attaque croissante (+d'atta = +de rang) des cartes d'une reserve
void RangAttaCroi(vector <Carte> reserve, vector <int>& rangs);
//meme chose qu'au dessus mais pour la magie
void RangMagCroi(vector <Carte> reserve, vector <int>& rangs);
//range un vecteur de carte en fonction de leur score décroissant (attaque + magie + défense)
void RangerScore(vector <Carte>& pile);
//range de manière décroissante avec ces critères (du plus important au moins important) : attaque > magie > défense
void Ranger(vector <Carte>& pile);
//cherche une carte avec pour nom <word> dans le vecteur <pile> et renvoie la carte si trouvée via <lacarte>
bool searchCarte(string word, vector <Carte> pile, Carte& lacarte);
//meme recherche de searchCarte mais lorsque le vecteur <pile> est triée avec le nom des cartes dans l'ordre alphabétique.
bool searchDichoCarte(string word, vector <Carte> pile, Carte& lacarte);
//mélange aleatoirement
void RangerAlea(vector <Carte>& pile);
//défini un deck de 20 cartes aléatoires de la reserve
void AleaDeck(vector <Carte> reserve, vector <Carte>& deck);

#endif
