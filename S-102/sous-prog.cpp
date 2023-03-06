#include <iostream>
#include <vector>
#include "carte.h"
#include "jeu.h"
#include "joueur.h"
#include "sous-prog.h"

#include <algorithm>
#include <random>
#include <chrono>

void RangerAtta(vector <Carte>& pile) {
    unsigned int cpt;
    int point;
    //int tours = 0;
    Carte tampon;
    for (cpt=0;cpt<pile.size()-1;cpt++) {
        point = cpt+1;
        //if (!pile[point].getAtta()<pile[point-1].getAtta()) tours++;
        while (pile[point].getAtta()<pile[point-1].getAtta()) {
            //cout << tours << endl;
            //cout << point << " vs "<< point-1 << endl;
            //pile[point-1].afficherCourt(); pile[point].afficherCourt();
            tampon = pile[point];
            pile[point] = pile[point-1];
            pile[point-1] = tampon;
            if (point>1) point--;
            //tours++;
        }
    }
}
///-----------Déroulement d'une partie : question 5.1------------
void RangAttaCroi(vector <Carte> reserve, vector <int>& rangs) {
    unsigned int cpt;
    int point;
    int tampon;
      //int tours = 0;
    vector <int> indtri;
    rangs = {};
    //définir le rang des cartes
    for (cpt=0;cpt<reserve.size();cpt++) {
        indtri.push_back(cpt);
    }
    for (cpt=0;cpt<indtri.size()-1;cpt++) {
        point = cpt;
        while (reserve[indtri[point]].getAtta()>reserve[indtri[point+1]].getAtta()) {
              //cout << tours << endl;
              //cout << point << " vs "<< point+1 << endl;
              //reserve[indtri[point]].afficherCourt(); reserve[indtri[point+1]].afficherCourt();
            tampon = indtri[point];
            indtri[point] = indtri[point+1];
            indtri[point+1] = tampon;
            if (point>0) point--;
              //tours++;
        }
    }
    //affecter le rang aux indices des cartes de la réserve

    for (cpt=0;cpt<reserve.size();cpt++) {
        rangs.push_back(0);
    }
    for (cpt=0;cpt<indtri.size();cpt++) {
          //cout << cpt << " - indtri : "<<indtri[cpt]<<endl;
        rangs[indtri[cpt]] = cpt;
    }
}
///-----------Déroulement d'une partie : question 5.2------------
void RangMagCroi(vector <Carte> reserve, vector <int>& rangs) {
    unsigned int cpt;
    int point;
    int tampon;
      //int tours = 0;
    vector <int> indtri;
    rangs = {};
    //définir le rang des cartes
    for (cpt=0;cpt<reserve.size();cpt++) {
        indtri.push_back(cpt);
    }
    for (cpt=0;cpt<indtri.size()-1;cpt++) {
        point = cpt;
        while (reserve[indtri[point]].getMag()>reserve[indtri[point+1]].getMag()) {
              //cout << tours << endl;
              //cout << point << " vs "<< point+1 << endl;
              //reserve[indtri[point]].afficherCourt(); reserve[indtri[point+1]].afficherCourt();
            tampon = indtri[point];
            indtri[point] = indtri[point+1];
            indtri[point+1] = tampon;
            if (point>0) point--;
              //tours++;
        }
    }
    //affecter le rang aux indices des cartes de la réserve

    for (cpt=0;cpt<reserve.size();cpt++) {
        rangs.push_back(0);
    }
    for (cpt=0;cpt<indtri.size();cpt++) {
          //cout << cpt << " - indtri : "<<indtri[cpt]<<endl;
        rangs[indtri[cpt]] = cpt;
    }
}

///-----------Déroulement d'une partie : question 7------------
void Ranger(vector <Carte>& pile) {
    unsigned int cpt;
    int point;
    int tours = 0;
    Carte tampon;
    ///range l'attaque décroissante
    for (cpt=0;cpt<pile.size()-1;cpt++) {
        point = cpt+1;
        while (pile[point].getAtta()>pile[point-1].getAtta()) {
            tampon = pile[point];
            pile[point] = pile[point-1];
            pile[point-1] = tampon;
            if (point>1) point--;
        }
    }
    ///range la magie décroissante
    for (cpt=0;cpt<pile.size();cpt++) {
        point = cpt;
        while (pile[point].getMag()<pile[point+1].getMag() && pile[point].getAtta()==pile[point+1].getAtta()) {
            tampon = pile[point];
            pile[point] = pile[point+1];
            pile[point+1] = tampon;
            if (point>0) point --;
        }
    }
    ///range la défense décroissante
    for (cpt=0;cpt<pile.size();cpt++) {
        point = cpt;
        while (pile[point].getDef()<pile[point+1].getDef() && pile[point].getAtta()==pile[point+1].getAtta() && pile[point].getMag()==pile[point+1].getMag()) {
            tampon = pile[point];
            pile[point] = pile[point+1];
            pile[point+1] = tampon;
            if (point>0) point --;
        }
    }
}

///-----------Déroulement d'une partie : question 8------------
void RangerScore(vector <Carte>& pile) {
    unsigned int cpt;
    int point;
    int tours = 0;
    Carte tampon;
    for (cpt=0;cpt<pile.size()-1;cpt++) {
        point = cpt+1;
        //if (!pile[point].getAtta()<pile[point-1].getAtta()) tours++;
        while (pile[point].Score()>pile[point-1].Score()) {
            //cout << tours << endl;
            //cout << point << " vs "<< point-1 << endl;
            //pile[point-1].afficherCourt(); pile[point].afficherCourt();
            tampon = pile[point];
            pile[point] = pile[point-1];
            pile[point-1] = tampon;
            if (point>1) point--;
            tours++;
        }
    }
}

///-----------Déroulement d'une partie : question 9------------
//-----a-----
bool searchCarte(string word, vector <Carte> pile, Carte& lacarte) {
    bool trouve = false;
    unsigned int cpt = 0;
    while (!trouve && cpt<pile.size()) {
        trouve = word==pile[cpt].getName();
        cpt ++;
    }
    if (trouve) lacarte = pile[cpt-1];

    return trouve;
}
//-----b-----
bool searchDichoCarte(string word, vector <Carte> pile, Carte& lacarte) {
    bool trouve = false;
    int indStart = 0;
    int indEnd = pile.size()-1;
    int indTest;
    while (!trouve && indStart <= indEnd) {
        indTest = indStart+((indEnd-indStart)/2);
        trouve = word==pile[indTest].getName();
        if (pile[indTest].getName()<word) {
            indStart = indTest+1;
        } else {
            indEnd = indTest-1;
        }
    }

    if (trouve) lacarte = pile[indTest];

    return trouve;
}

void RangerAlea(vector <Carte>& pile) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (pile.begin(), pile.end(), std::default_random_engine(seed));
}
void AleaDeck(vector <Carte> reserve, vector <Carte>& deck) {
    unsigned int cpt;
    RangerAlea(reserve);
    for (cpt=0;cpt<20;cpt++) {
      deck.push_back(reserve[cpt]);
    }
}
