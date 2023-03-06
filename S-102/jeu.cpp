#include "jeu.h"
#include <fstream>
#include <iostream>
#include <vector>

Jeu::Jeu() // le constructeur vide avec des valeurs par defaut
{
  _joueur1 = JOUEUR_VIDE;
  _joueur2 = JOUEUR_VIDE;
  _reserve = BASEDECK;
}

Jeu::Jeu(Joueur player1, Joueur player2,
         vector<Carte> reserve) // Constructeur avec  paramètres
{
  _joueur1 = player1;
  _joueur2 = player2;
  _reserve = reserve;
}

bool Jeu::fini(Joueur &vainqueur) const {
  if (!_joueur1.resteDuPrestige() && _joueur2.resteDuPrestige()) {
    vainqueur = _joueur2;
  } else if (_joueur1.resteDuPrestige() && !_joueur2.resteDuPrestige()) {
    vainqueur = _joueur1;
  }
  return this->estFini();
}
bool Jeu::estFini() const {
  int nbCarte;
  return (!_joueur1.resteDuPrestige() || !_joueur2.resteDuPrestige());
}
int Jeu::winner()const {
     // retourne +1 si Joueur1 gagne, -1 si Joueur2 gagne et 0 si match nul
  Joueur gagnant;
  int result;
  if (this->fini(gagnant) && gagnant.memeJoueur(_joueur1)) {
    result = 1;
  } else if (this->fini(gagnant) && gagnant.memeJoueur(_joueur2)) {
    result = -1;
  } else if (this->estFini()) {
    result = 0;
  }
  return result;
}
void Jeu::reserve_init(string donneCarte){
  ifstream donne_carte;
  string ligne;
  Carte t;
  donne_carte.open(donneCarte);
  do{
    donne_carte>>ligne;
    t.remplir(ligne);
    _reserve.push_back(t);
  }
    while(!donne_carte.eof());
  for(int j=1;j<_reserve.size();j++){
    t=_reserve[j];
    int i=j-1;
    while(i>=0 && _reserve[i].getName()>t.getName()){
      _reserve[i+1]=_reserve[i];
        i=i-1;
    }
    _reserve[i+1]=t;
  }
}
void Jeu::giveReserve(vector<Carte>& reserve) {
  unsigned int cpt;
  for(cpt=0;cpt<_reserve.size();cpt++) {
    reserve.push_back(_reserve[cpt]);
  }
}
void Jeu::PrestUpdate(Joueur player1, Joueur player2) {
  _joueur1.setprest(player1.sonPrestige());
  _joueur2.setprest(player2.sonPrestige());
}
void Jeu::NameUpdate(Joueur player1, Joueur player2) {
  _joueur1.rename(player1.sonNom());
  _joueur2.rename(player2.sonNom());
}
