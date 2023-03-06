/*

#include <iostream>
#include "carte.h"
#include "jeu.h"
#include "joueur.h"
#include "sous-prog.h"
#include <fstream>

using namespace std;

int main() 
{
    Carte cv;
    Carte c1("yoyo",5,1,8);
    Carte cr1 ("MainDroite",1,0,0);
    Carte cr2 ("MainGauche",0,1,0);
    Carte cr3 ("Tete",1,-2,0);
    Carte cr4 ("Bouche",1,-1,2);
    Carte cr5 ("Genou",2,0,0);
    Carte card;
    vector<Carte> pile = {cv,c1,cr1,cr2,cr3,cr4,cr5};
    vector<Carte> piletriee = {cr4,cr5,cr1,cr2,cr3,c1};
    vector<Carte> dec1 = {cv,cv};
    vector<Carte> dec0;

    Joueur playerZero;
    Joueur playerOne ("Parzival", dec1, 13);
    Joueur playerDed ("name", dec0, 0);
    Joueur vainqueur;

    Jeu game0;
    Jeu game1(playerOne, playerZero, pile);
    Jeu game2(playerDed, playerOne, pile);
    Jeu game3(playerOne, playerDed, pile);
    Jeu game4(playerDed, playerDed, pile);
    
    playerOne.affiche(); //doit afficher : Le joueur Parzival a 13 points de prestige, il reste 2 cartes dans sa pile.
    playerZero.affiche(); //doit afficher : Le joueur Yugi a 25 points de prestige, il reste 5 cartes dans sa pile.

    playerOne.JouentUneCarte(playerZero);
    playerOne.affiche(); //doit afficher : Le joueur Parzival a 12 points de prestige, il reste 1 cartes dans sa pile.
    playerZero.affiche(); //doit afficher : Le joueur Yugi a 25 points de prestige, il reste 4 cartes dans sa pile.
  
    //----------tests automatiques de la classe Carte----------
    cout << "---Tests automatiques de la classe Carte---"<<endl;
    if (cr1.degatMagique(cr2)==0){
     cout<<"Test de degat Magique reussie"<<endl;
   }
  else{
    cout<< "Test de degat Magique rate"<<endl;
  }
  if(c1.degatPhysique(cr1)==-5){
    cout<<"Test de degat Physique reussie"<<endl;
   }
  else{
    cout<< "Test de degat Physique rate"<<endl;
  }
  
    //----------tests automatiques de la classe Joueur----------
    cout << "---Tests automatiques de la classe Joueur---"<<endl;
    //test de sonNom()
    if (playerOne.sonNom()=="Parzival") {
        cout << "Test 1 de sonNom reussi !"<<endl;
    } else {
        cout << "Test 1 de sonNom rate :/"<<endl;
    }
    if (playerOne.sonNom()!="Roul") {
        cout << "Test 2 de sonNom reussi !"<<endl;
    } else {
        cout << "Test 2 de sonNom rate :/"<<endl;
    }
    //test de sonPrestige()
    if (playerOne.sonPrestige()==12) {
        cout << "Test 1 de sonPrestige reussi !"<<endl;
    } else {
        cout << "Test 1 de sonPrestige rate :/"<<endl;
    }
    if (playerOne.sonPrestige()!=25) {
        cout << "Test 2 de sonPrestige reussi !"<<endl;
    } else {
        cout << "Test 2 de sonPrestige rate :/"<<endl;
    }
    //test de resteDesCartes()
    int o;
    if (playerOne.resteDesCartes(o)) {
        cout << "Test 1 de resteDesCartes reussi !" << endl;
    } else {
        cout << "Test 1 de resteDesCartes rate :/" << endl;
    }
    if (!playerDed.resteDesCartes(o)) {
        cout << "Test 2 de resteDesCartes reussi !" << endl;
    } else {
        cout << "Test 2 de resteDesCartes rate :/" << endl;
    }
    //test de resteDuPrestige()
    if (playerOne.resteDuPrestige()) {
        cout << "Test 1 de resteDuPrestige reussi !" << endl;
    } else {
        cout << "Test 1 de resteDuPrestige rate :/" <<endl;
    }
    if (!playerDed.resteDuPrestige()) {
        cout << "Test 2 de resteDuPrestige reussi !" << endl;
    } else {
        cout << "Test 2 de resteDuPrestige rate :/" <<endl;
    }
    //test de memeJoueur()
    if (playerOne.memeJoueur(playerOne)) {
        cout << "Test 1 de memeJoueur reussi !"<<endl;
    } else {
        cout << "Test 1 de memeJoueur rate :/"<<endl;
    }
    if (!playerOne.memeJoueur(playerZero)) {
        cout << "Test 2 de memeJoueur reussi !"<<endl;
    } else {
        cout << "Test 2 de memeJoueur rate :/"<<endl;
    }
    cout << endl;

    //----------tests automatiques de la classe Jeu----------
    cout << "---Tests automatiques de la classe Jeu---"<<endl;
    //test de fini()
    if (!game1.fini(vainqueur)) {
        cout << "Test 1 de fini reussi !"<<endl;
    } else {
        cout << "Test 1 de fini rate :/"<<endl;
    }
    if (game2.fini(vainqueur) && vainqueur.memeJoueur(playerOne)) {
        cout << "Test 2 de fini reussi !"<<endl;
    } else {
        cout << "Test 2 de fini rate :/"<<endl;
    }
    //test de estFini()
    if (!game1.estFini()) {
        cout << "Test 1 de estFini reussi !"<<endl;
    } else {
        cout << "Test 1 de estFini rate :/"<<endl;
    }
    if (game2.estFini()) {
        cout << "Test 2 de estFini reussi !"<<endl;
    } else {
        cout << "Test 2 de estFini rate :/"<<endl;
    }
    if (game3.estFini()) {
        cout << "Test 3 de estFini reussi !"<<endl;
    } else {
        cout << "Test 3 de estFini rate :/"<<endl;
    }
    //test de winner()
    if (game2.winner()==-1) {
        cout << "Test 1 de winner reussi !"<<endl;
    } else {
        cout << "Test 1 de winner rate :/"<<endl;
    }
    if (game3.winner()==1) {
        cout << "Test 2 de winner reussi !"<<endl;
    } else {
        cout << "Test 2 de winner rate :/"<<endl;
    }
    if (game4.winner()==0) {
        cout << "Test 3 de winner reussi !"<<endl;
    } else {
        cout << "Test 3 de winner rate :/"<<endl;
    }
    //----------tests automatiques des sous programmes----------
    cout << "---Tests automatiques des sous-programmes---"<<endl;
    //test de searchCarte()
    if (searchCarte("Tete", pile, card) && card.getName()==cr3.getName() && card.getAtta()==cr3.getAtta() && card.getDef()==cr3.getDef() && card.getMag()==cr3.getMag()) {
        cout << "Test 1 de searchCarte reussi !"<<endl;
    } else {
        cout << "Test 1 de searchCarte rate :/"<<endl;
    }
    if (!searchCarte("Donuts", pile, card)) {
        cout << "Test 2 de searchCarte reussi !"<<endl;
    } else {
        cout << "Test 2 de searchCarte rate :/"<<endl;
    }
    //test de searchDichoCarte()
    if (searchDichoCarte("Tete", piletriee, card) && card.getName()==cr3.getName() && card.getAtta()==cr3.getAtta() && card.getDef()==cr3.getDef() && card.getMag()==cr3.getMag()) {
        cout << "Test 1 de searchDichoCarte reussi !"<<endl;
    } else {
        cout << "Test 1 de searchDichoCarte rate :/"<<endl;
    }
    if (!searchDichoCarte("Donuts", piletriee, card)) {
        cout << "Test 2 de searchDichoCarte reussi !"<<endl;
    } else {
        cout << "Test 2 de searchDichoCarte rate :/"<<endl;
    }
  
    cout << "Hello World!\n";
    return 0;
ifstream fileReader("./donneCarte.txt"); //Ouverture d'un fichier en lecture     
string ligne;
  getline(fileReader, ligne);
}

*/
