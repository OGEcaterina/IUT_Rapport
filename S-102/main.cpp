
#include <iostream>
#include "carte.h"
#include "jeu.h"
#include "joueur.h"
#include "sous-prog.h"

using namespace std;

int main()
{
bool restart;
string reply;
string gamemode;
int intReply;
Joueur vainqueur;
int nbCarte;
try{
do {
  vector<Carte>reserve = {};
  Joueur player1;
  Joueur player2;
  Jeu game(player1, player2, reserve);
  game.reserve_init("donneCarte.txt");
  game.giveReserve(reserve);
  unsigned int cpt;

  ///propose les differents modes de jeu
  cout << "Dans quel mode de jeux voulez-vous jouer ? Joueur contre joueur (jcj) ou joueur contre IA (jce) ? ";
  cin >> reply;
  while (reply != "jcj" && reply !="jce") {
    cout << "r�ponse incorrecte, veuillez recommencer"<<endl;
    cout << "Dans quel mode de jeux voulez-vous jouer ? Joueur contre joueur (jcj) ou joueur contre ia (jce) ? ";
    cin >> reply;
  }
  gamemode = reply;
  ///demande le nom des joueurs humains
  if (reply=="jcj") {
    //construction d'une partie joueur contre joueur
    cout << "Quel sera le nom du premier joueur ? ";
    cin >> reply;
    player1.rename(reply);
    cout << "Quel sera le nom du deuxieme joueur ? ";
    cin >> reply;
    player2.rename(reply);
  } else {
    //construction d'une partie joueur contre IA
    cout << "Quel sera le nom du joueur ? ";
    cin >> reply;
    player1.rename(reply);
  }
  game.NameUpdate(player1, player2);
  ///affichage des r�gles du jeu
  cout << endl;
  cout << "Pr�sentation du jeu :"<<endl;
  cout << "Le jeu consiste en l'affrontement de deux joueurs tr�s prestigieux (ils ont 25 points de prestige) chacun muni d'une pile de 20 cartes s�lectionn�es � partir d'une r�serve identique."<<endl;
  cout << "Chaque carte a trois statistiques :"<<endl;
  cout << "\t - Une valeur d'attaque physique,"<<endl;
  cout << "\t - Une valeur de puissance magique et,"<<endl;
  cout << "\t - Une valeur de d�fense physique."<<endl;
  cout << "L'objectif est de r�duire les points de prestige de son adversaire et de d�fendre les siens."<<endl;
  cout << "Le vainqueur est le premier � envoyer son adversaire dans la boue (prestige � z�ro) ou d'avoir plus de prestige que son adversaire� la fin de l'affrontement (lorsqu'il n'y a pas de carte ou lorsque les deux joueurs sont dans le n�gatif)."<<endl;
  cout << endl << "Comment jouer ?"<<endl;
  cout << "L'int�r�t du jeu r�side dans le choix de ses cartes et leur ordre. A vous de trouver la meilleure combinaison de cartes pour envoyer votre adversaire au tapis !"<<endl<<endl;

  ///affichage des cartes disponibles (reserve)
  cout << "Voici les cartes disponibles dans la reserve :"<<endl;
  for (cpt=0;cpt<reserve.size();cpt++) {
    reserve[cpt].afficherCourt();
  }

  ///proposition et choix de strat�gie pour le joueur
  cout << "----------Joueur 1----------"<<endl;
  cout << "Pour quelle strat�gie voulez-vous opter ?"<< endl;
  cout << "\t 1- R�cuperer les cartes avec le plus d'attaque physique"<<endl;
  cout << "\t 2- R�cuperer les cartes avec le plus d'attaque magique"<<endl;
  cout << "\t 3- Choisir vous-m�me"<<endl;
  cin >> intReply;
  while (intReply<1 || intReply>3) {
    cout << "r�ponse incorrecte, veuillez r�pondre 1, 2 ou 3 :";
    cin >> intReply;
  }
  switch (intReply) {
    case 1:
      cout << "Vous avez choisi les cartes avec le plus d'attaque physique. La brutalit�e paie parfois..."<<endl;
      player1.setAttaDeck(reserve);
      break;
    case 2:
      cout << "Vous avez choisi les cartes avec le plus d'attaque magique. Adepte de Gandalf ?"<<endl;
      player1.setMagDeck(reserve);
      break;
    case 3:
      cout << "Vous avez choisi de selectionner les cartes par vous-m�me. Bonne r�flexion !"<<endl;
      player1.ChooseDeck(reserve);
      break;
    default:
      cout << "Vous aurez les cartes avec le plus d'attaque physique"<<endl;
      player1.setAttaDeck(reserve);
  }
  if (gamemode=="jcj") {
    //d�finition du deck du joueur 2 humain
    cout << "----------Joueur 2----------"<<endl;
    cout << "Pour quelle strat�gie voulez-vous opter ?"<< endl;
    cout << "\t 1- R�cuperer les cartes avec le plus d'attaque physique"<<endl;
    cout << "\t 2- R�cuperer les cartes avec le plus d'attaque magique"<<endl;
    cout << "\t 3- Choisir vous-m�me"<<endl;
    cin >> intReply;
    while (intReply<1 || intReply>3) {
      cout << "r�ponse incorrecte, veuillez r�pondre 1, 2 ou 3 :";
      cin >> intReply;
    }
    switch (intReply) {
      case 1:
        cout << "Vous avez choisi les cartes avec le plus d'attaque physique. La brutalit�e paie parfois..."<<endl;
        player2.setAttaDeck(reserve);
        break;
      case 2:
        cout << "Vous avez choisi les cartes avec le plus d'attaque magique. Adepte de Gandalf ?"<<endl;
        player2.setMagDeck(reserve);
        break;
      case 3:
        cout << "Vous avez choisi de selectionner les cartes par vous-m�me. Bonne r�flexion !"<<endl;
        player2.ChooseDeck(reserve);
        break;
      default:
        cout << "Vous aurez les cartes avec le plus d'attaque physique"<<endl;
        player2.setAttaDeck(reserve);
    }
  } else {
    //d�finition du deck de l'IA joueur2
    cout << "----------Joueur 2----------"<<endl;
    cout << "Quelle difficult�e choisissez-vous ?"<<endl;
    cout << "\t 1- Facile"<<endl;
    cout << "\t 2- Moyen"<<endl;
    cout << "\t 3- Difficile"<<endl;
    cout << "\t 4- Tr�s Difficile"<<endl;
    cout << "\t 5- Aleatoire"<<endl;
    cin >> intReply;
    while (intReply<1 || intReply>5) {
      cout << "r�ponse incorrecte, veuillez r�pondre 1, 2, 3, 4 ou 5 :";
      cin >> intReply;
    }
    switch (intReply) {
      case 1:
        cout << "Vous avez choisi le mode facile, bonne partie !"<<endl;
        player2.setAttaDeck(reserve);
        break;
      case 2:
        cout << "Vous avez choisi le mode moyen, c'est parti !"<<endl;
        player2.setMagDeck(reserve);
        break;
      case 3:{
        cout << "Vous avez choisi le mode difficile, a vos risques et p�rils !"<<endl;
        vector<Carte> deckIA;
        AleaDeck(reserve, deckIA);
        Ranger(deckIA);
        player2.setDeck(deckIA);
        break;}
      case 4:{
        cout <<"Vous avez choisi le mode tr�s difficile, vous aimez le d�fi !"<<endl;
        vector<Carte> deckIA;
        AleaDeck(reserve, deckIA);
        RangerScore(deckIA);
        player2.setDeck(deckIA);
        break;}
      case 5:{
        cout << "Vous avez choisi le mode aleatoire, que la chance soit avec vous !"<<endl;
        vector<Carte> deckIA;
        AleaDeck(reserve, deckIA);
        player2.setDeck(deckIA);
        break;}
      default:
        cout << "Vous aurez les cartes avec le plus d'attaque physique"<<endl;
        player2.setAttaDeck(reserve);
    }
  }

  ///laisse le joueur modifier sa pile
  cout <<"----------Joueur 1----------"<<endl;
  player1.afficheDeck();
  cout << "Voulez-vous modifier votre deck ? (o pour oui)";
  cin >> reply;
  if (reply=="o" || reply=="O" || reply=="oui") {
    int ind1, ind2;
    do {
      cout << "Quel est le nom de la 1ere carte que vous voulez changer ? (nimporte pour arr�ter)"<<endl;
      cin >> reply;
      ind1 = player1.searchInd(reply);
      cout << "Quel est le nom de la 2eme carte que vous voulez changer ? (stop pour arr�ter)"<<endl;
      cin >> reply;
      ind2 = player1.searchInd(reply);
      if (reply!="stop") {
        player1.changeDeck(ind1, ind2);
        player1.afficheDeck();
      }
    } while (reply!="stop");
  }
  if (gamemode=="jcj") {
    cout <<"----------Joueur 2----------"<<endl;
    player2.afficheDeck();
    cout << "Voulez-vous modifier votre deck ? (o pour oui)";
    cin >> reply;
    if (reply=="o" || reply=="O" || reply=="oui") {
      int ind1, ind2;
      do {
        cout << "Quel est le nom de la 1ere carte que vous voulez changer ? (nimporte pour arr�ter)"<<endl;
        cin >> reply;
        ind1 = player2.searchInd(reply);
        cout << "Quel est le nom de la 2eme carte que vous voulez changer ? (stop pour arr�ter)"<<endl;
        cin >> reply;
        ind2 = player2.searchInd(reply);
        if (reply!="stop") {
          player2.changeDeck(ind1, ind2);
          player2.afficheDeck();
        }
      } while (reply!="stop");
    }
  }

  ///d�roule la partie et affiche les combats
  int tours = 0;
  while (!game.fini(vainqueur) && player1.resteDesCartes(nbCarte) && player2.resteDesCartes(nbCarte)) {

    cout << "Ecrivez 'next' pour effectuer le prochain combat :";
    cin>>reply;
    while (reply!="next") {
      cout << "R�ponse incorrecte, veuillez �crire 'suivant pour effectuer le prochain combat :'";
      cin >> reply;
    }
    tours++;
    cout << "----------Tour num�ro "<<tours<<"----------"<<endl;
    player1.JouentUneCarte(player2);
    game.PrestUpdate(player1, player2);
  }
  ///affiche le vainqueur
  cout << "Fin de la partie !" << endl;
  if (game.winner()!=0) {
    cout << "Bravo � "<<vainqueur.sonNom()<<" qui remporte la partie avec "<<vainqueur.sonPrestige()<<" points de prestige restant !!!"<<endl;
  } else {
    cout << "Dommage ! Ce combat acharn� a donc fini par un match nul... Peut �tre pourriez-vous battre votre adversaire lors d'une prochaine partie ?"<<endl;
    player1.affiche();
    player2.affiche();
  }


  ///propose de recommencer une partie
  cout << "Voulez-vous recommencer une partie ? (o pour oui)"<<endl;
  cin>>reply;
  restart = reply=="o" || reply=="O" || reply=="oui";
} while (restart);

cout << "fin de la session"<<endl;
}
catch (out_of_range& e) {
    cout << e.what()<<endl;
}

return 0;
}
