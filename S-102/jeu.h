#ifndef JEU_H
#define JEU_H
#include <vector>
#include "carte.h"
#include "joueur.h"

const Joueur JOUEUR_VIDE;

class Jeu
{
    private:
        Joueur _joueur1;
        Joueur _joueur2;
        vector<Carte>_reserve;
    public:
        Jeu();// Constructeur    vide
        Jeu(Joueur player1, Joueur player2, vector <Carte> reserve );//Constructeur avec  paramètres
       vector <Carte> reserve;
        bool fini(Joueur & vainqueur)const;
        bool estFini()const;
        int winner()const; //retourne +1 si Joueur1 gagne, -1 si Joueur2 gagne et 0 si match nul
        void reserve_init(string);//fonction //membre prenent en paramètre une //chaîne de caractère correspondant au
        //nom d’un fichier contenant les
        //données des cartes et qui remplit la
        //reserve du Jeu.
        void giveReserve(vector<Carte>& reserve);
        void PrestUpdate(Joueur player1, Joueur player2);
        void NameUpdate(Joueur player1, Joueur player2);

};
#endif // JEU_H
