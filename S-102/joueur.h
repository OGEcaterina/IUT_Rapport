#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <vector>
#include <string>
#include "carte.h"

using namespace std;

const Carte MDROITE ("MainDroite",1,0,0);
const Carte MGAUCHE ("MainGauche",0,1,0);
const Carte TETE ("Tete",1,-2,0);
const Carte BOUCHE("Bouche",1,-1,2);
const Carte GENOU ("Genou",2,0,0);
const vector<Carte> BASEDECK = {MDROITE,MGAUCHE,TETE,BOUCHE,GENOU};

class Joueur {
private:
    string _nom;    //nom du joueur
    int _prest;      //points de prestige
    vector <Carte> _pile; //cartes du joueur

public :
    //constructeur vide
    Joueur();
    //constructeur nm
    Joueur(string nom, vector<Carte> deck=BASEDECK, int prestige=25);

    //retourne le nom du joueur
    string sonNom()const;
    //retourne les points de prestige du joueur
    int sonPrestige()const;
    //affiche le joueur
    void affiche();
    //initialiser son deck
    void initDeck(vector <Carte> reserve);
    //verifie si il reste des cartes dans la pile
    bool resteDesCartes(int& NbCarte)const;
    //verifie si il reste des points de prestige en positif
    bool resteDuPrestige()const;
    //renvoie par le paramètre carteCible  et retire de la pile la prochaine carte de la pile du joueur
    void CarteSuiv(Carte& carteCible);
    //joue une carte et met a jour les pts de prestige
    void JouentUneCarte (Joueur& player2);

    //initialise le deck (_pile du joueur cible) en le laissant choisir 20 cartes de la réserve
    void ChooseDeck(vector <Carte> reserve);
    //meme fonction qu'au dessus mais avec utilisation de recherche dichotomique
    void ChooseSortedDeck(vector <Carte> reserve);
    //choisis un deck avec les cartes ayant le plus d'attaque de la reserve
    void setAttaDeck(vector <Carte> reserve);
    //choisis un deck avec les cartes ayant le plus d'attaque de la reserve
    void setMagDeck(vector <Carte> reserve);

    void setDeck(vector<Carte> deck);
    void rename(string newname);
    void setprest(int newprest);
    bool memeJoueur(Joueur player2)const;
    void changeDeck(int ind1, int ind2);
    void afficheDeck()const;
    //retourne l'indice dans le vecteur de la carte ayant pour nom <lfname>
    int searchInd(string lfname)const;
};

#endif // JOUEUR_H_INCLUDED
