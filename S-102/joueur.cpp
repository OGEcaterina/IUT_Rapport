#include <iostream>
#include "joueur.h"
#include "sous-prog.h"
#include <vector>

using namespace std;

Joueur::Joueur() {
    _nom="Yugi";
    _prest=25;
    _pile = BASEDECK;
}
Joueur::Joueur(string nom, vector<Carte> deck, int prestige) {
    _nom = nom;
    _prest = prestige;
    _pile = deck;
}

string Joueur::sonNom()const {
    return _nom;
}
int Joueur::sonPrestige()const {
    return _prest;
}

void Joueur::affiche() {
    cout << "Le joueur "<<_nom<<" a "<<_prest<<" points de prestige, il reste "<<_pile.size()<<" cartes dans sa pile."<<endl;
}
void Joueur::initDeck(vector<Carte> reserve) {
    unsigned int cpt;
    if(reserve.size()<20) throw(out_of_range("pas assez de cartes dans la reserve (- de 20)"));
    for (cpt=0;cpt<20; cpt++) {
      _pile.push_back(reserve[cpt]);
    }
}

bool Joueur::resteDesCartes(int& NbCarte)const {
    NbCarte = _pile.size();
    return _pile.size()>=1;
}
bool Joueur::resteDuPrestige()const {
    return !(_prest==0);
}
void Joueur::CarteSuiv(Carte& carteCible) {
    int ble;
    if (!resteDesCartes(ble)) throw(out_of_range("impossibilitee de jouer, plus de cartes dans la pile"));
    carteCible = _pile[_pile.size()-1];
    _pile.pop_back();
}
void Joueur::JouentUneCarte (Joueur& player2) {
    int nbCartes;
    if (!this->resteDesCartes(nbCartes) && !player2.resteDesCartes(nbCartes)) throw(out_of_range("impossible de jouer, plus de cartes dans la pile d'un joueur"));
    Carte pl1c;
    Carte pl2c;
    this->CarteSuiv(pl1c);
    player2.CarteSuiv(pl2c);

    int dgtsP = pl1c.degatPhysique(pl2c);
    int dmgP;
    int dgtsM = pl1c.degatMagique(pl2c);

    //affichage des stats du combat de cartes
    cout << _nom << " : "<<pl1c.getName()<<" attaque " << pl1c.getAtta() << ", defense "<<pl1c.getDef()<<", magie "<<pl1c.getMag()<<" --Vs-- "<<player2.sonNom()<<" : "<<pl2c.getName()<<" attaque "<<pl2c.getAtta()<<", defense "<<pl2c.getDef()<<", magie "<<pl2c.getMag()<<endl;

    //affichage des stats du combat de cartes pour le réglement des degats physiques
    //cout << _nom << " : att " << pl1c.getAtta() << ", def "<<pl1c.getDef()<<" --Vs-- "<<player2.sonNom()<<" : att "<<pl2c.getAtta()<<", def "<<pl2c.getDef()<<endl;
    if (dgtsP>0) {
        //attribution des degats au joueur 1 (cible)
        if (dgtsP>=_prest) {
            _prest = 0;
        } else {
            _prest -= dgtsP;
        }
        //résumé de l'action sur le joueur 1 (cible)
        cout << "Le joueur "<<_nom<<" a subit "<<dgtsP<<" degat(s) physique(s), il lui reste "<<_prest<<"pts de prestige"<<endl;
    } else if (dgtsP<0) {
        //attribution des degats au joueur 2 (parametre)
        if (-dgtsP>=player2.sonPrestige()) {
            player2.setprest(0);
        } else {
            player2.setprest(player2.sonPrestige()+dgtsP);
        }
        //résumé de l'action sur le joueur 2 (parametre)
        cout << "Le joueur "<<player2.sonNom()<<" a subit "<<-dgtsP<<" degat(s) physique(s), il lui reste "<<player2.sonPrestige()<<"pts de prestige"<<endl;
    }
    if (dgtsP==0) {
        cout << "Aucun degat physique n est inflige" << endl;
    }

    //affichage des stats du combat de cartes pour le réglement des degats magiques

    if (dgtsM>0) {
        //attribution des degats au joueur 1 (cible)
        if (dgtsM>=_prest) {
            _prest = 0;
        } else {
            _prest -= dgtsM;
        }
        //résumé de l'action sur le joueur 1 (cible)
        cout << "Le joueur "<<_nom<<" a subit "<<dgtsM<<" degat(s) magique(s), il lui reste "<<_prest<<"pts de prestige"<<endl;
    } else if (dgtsM<0) {
        //attribution des degats au joueur 2 (parametre)
        if (-dgtsM>=player2.sonPrestige()) {
            player2.setprest(0);
        } else {
            player2.setprest(player2.sonPrestige()+dgtsM);
        }
        //résumé de l'action sur le joueur 2 (parametre)
        cout << "Le joueur "<< player2.sonNom() <<" a subit "<<-dgtsM<<" degats magiques, il lui reste "<<player2.sonPrestige()<<"pts de prestige"<<endl;
    } else if (dgtsM==0) {
        cout << "Aucun degat magique n est inflige" << endl;
    }
}
void Joueur::setprest(int newprest) {
    _prest = newprest;
}
bool Joueur::memeJoueur(Joueur player2)const {
    return (_nom==player2.sonNom());
}

void Joueur::ChooseDeck(vector<Carte> reserve) {
    if(reserve.size()<20) throw(out_of_range("pas assez de cartes dans la reserve (- de 20)"));
    unsigned int cpt;
    string choix;
    Carte card;
    //présentation des cartes de la réserve
    cout << "Choisissez 20 cartes en écrivant leurs noms parmis celles-ci :"<<endl;
    for (cpt=0;cpt<reserve.size();cpt++) {
        reserve[cpt].afficherCourt();
    }
    //choix des cartes
    for (cpt=0;cpt<20;cpt++) {
        cout << "choix de la carte "<<cpt+1<<"/20 :";
        cin >> choix;
        while (!searchCarte(choix, reserve, card) || searchCarte(choix, _pile, card)) {
            cout << "cette carte n'existe pas ou a déjà été choisie"<<endl;
            cout << "choix de la carte "<<cpt+1<<"/20 :";
            cin >> choix;
        }
        _pile.push_back(card);
    }
}
void Joueur::ChooseSortedDeck(vector<Carte> reserve) {
    if(reserve.size()<20) throw(out_of_range("pas assez de cartes dans la reserve (- de 20)"));
    unsigned int cpt;
    string choix;
    Carte card;
    //présentation des cartes de la réserve
    cout << "Choisissez 20 cartes en écrivant leurs noms parmis celles-ci :"<<endl;
    for (cpt=0;cpt<reserve.size();cpt++) {
        reserve[cpt].afficherCourt();
    }
    //choix des cartes
    for (cpt=0;cpt<20;cpt++) {
        cout << "choix de la carte "<<cpt<<"/20 :";
        cin >> choix;
        while (!searchDichoCarte(choix, reserve, card) || searchDichoCarte(choix, _pile, card)) {
            cout << "cette carte n'existe pas ou a déjà été choisie"<<endl;
            cout << "choix de la carte "<<cpt<<"/20 :";
            cin >> choix;
        }
        _pile.push_back(card);
    }
}
void Joueur::setAttaDeck(vector<Carte> reserve) {
    _pile = {};
    unsigned int cpt;
    vector <int> rangs;
    RangAttaCroi(reserve, rangs);
    for (cpt=0;cpt<reserve.size();cpt++) {
        if (rangs[cpt]>=(reserve.size()-20)) {
            _pile.push_back(reserve[cpt]);
        }
    }
}
void Joueur::setMagDeck(vector<Carte> reserve) {
    _pile = {};
    unsigned int cpt;
    vector <int> rangs;
    RangMagCroi(reserve, rangs);
    for (cpt=0;cpt<reserve.size();cpt++) {
        if (rangs[cpt]>=(reserve.size()-20)) {
            _pile.push_back(reserve[cpt]);
        }
    }
}
void Joueur::rename(string newname) {
    _nom = newname;
}
void Joueur::setDeck(vector<Carte> deck) {
    _pile = deck;
}
void Joueur::changeDeck(int ind1, int ind2) {
    if (ind1<0 || ind2<0 || ind1>=_pile.size() || ind2>= _pile.size()) throw(out_of_range("Joueur::changeDeck(), mauvais indices"));
    Carte tampon = _pile[ind1];
    _pile[ind1] = _pile[ind2];
    _pile[ind2] = tampon;
}
void Joueur::afficheDeck()const {
    unsigned int cpt;
    cout << "Deck de "<<_nom<<endl;
    for (cpt=0;cpt<_pile.size();cpt++) {
      _pile[cpt].afficherCourt();
    }
}
int Joueur::searchInd(string lfname)const {
  unsigned int cpt = 0;
  int ind;
  bool trouve = false;
  while (!trouve && cpt<_pile.size()) {
    trouve = lfname==_pile[cpt].getName();
    cpt++;
  }
  if (trouve) {
    ind = cpt-1;
  } else {
    ind = -1;
  }
  return ind;
}
