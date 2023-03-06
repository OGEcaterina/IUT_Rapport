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
//range un vecteur de carte en fonction de leur score d�croissant (attaque + magie + d�fense)
void RangerScore(vector <Carte>& pile);
//range de mani�re d�croissante avec ces crit�res (du plus important au moins important) : attaque > magie > d�fense
void Ranger(vector <Carte>& pile);
//cherche une carte avec pour nom <word> dans le vecteur <pile> et renvoie la carte si trouv�e via <lacarte>
bool searchCarte(string word, vector <Carte> pile, Carte& lacarte);
//meme recherche de searchCarte mais lorsque le vecteur <pile> est tri�e avec le nom des cartes dans l'ordre alphab�tique.
bool searchDichoCarte(string word, vector <Carte> pile, Carte& lacarte);
//m�lange aleatoirement
void RangerAlea(vector <Carte>& pile);
//d�fini un deck de 20 cartes al�atoires de la reserve
void AleaDeck(vector <Carte> reserve, vector <Carte>& deck);

#endif
