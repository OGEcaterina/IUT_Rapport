#include "carte.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std ;

Carte::Carte()///Le constructeur vide
{
    _nom="Main nues";
    _atta=1;
    _def=1;
    _mag=0;

}

Carte::Carte(string nom,int attaque,int defense,int magie)///Le constructeur avec les 4 arguments
{
    _nom=nom;
    _atta=attaque;
    _def=defense;
    _mag=magie;

}
void Carte::afficherCourt()const{
    cout<<_nom<<" ["<<_atta<<" ; "<<_def<<" ; "<<_mag<<" ] "<<endl;
}
void Carte::afficher()const{
    cout<<"**********************************************************"<<endl;
    cout<<"Nom : "<<_nom<<endl;
    cout<<"Attaque : "<<_atta<<endl;
    cout<<"Defense : "<<_def<<endl;
    cout<<"Magie : "<<_mag<<endl;
    cout<<"**********************************************************"<<endl;
}

  int Carte::degatPhysique(const Carte& c2)const {
    int degats;
    if (_atta>c2.getAtta()) {
      if (_atta>c2.getDef()) {
        degats = -_atta + c2.getDef();
      } else {
        degats = 0;
      }
    } else if (_atta<c2.getAtta()){
      if (c2.getAtta()>_def) {
        degats = c2.getAtta() - _def;
      } else {
        degats = 0;
      }
    } else {
      degats = 0;
    }
    return degats;
}

 int Carte::degatMagique(const Carte& c2)const {
    int degats;
    if (_mag>c2.getMag()) {
        degats = -_mag;
    } else if (_mag<c2.getMag()) {
        degats = c2.getMag();
    } else {
      degats =0;
    }
    return degats;
}

int Carte::getAtta()const {
    return _atta;
}
int Carte::getDef()const {
    return _def;
}
int Carte::getMag()const {
    return _mag;
}
string Carte::getName()const {
    return _nom;
}
int Carte::Score()const {
    return _atta+_def+_mag;
}
//function prend en parametre un string representant une ligne du fichier+ remplit les donnees carte
void  Carte::remplir(const string & ligne){
      string chaine=ligne;
      vector<string> dd_chaine;
      for(int i=0; i<4;i++){
        int i_delim=chaine.find(",");
        dd_chaine.push_back(chaine.substr(0,i_delim));
        chaine.replace(0,i_delim+1," " );
      }
  dd_chaine[0][0]=toupper(dd_chaine[0][0]);
      _nom=dd_chaine[0];
      _atta= int (stoi (dd_chaine[1]));
      _def=int (stoi(dd_chaine[2]));
      _mag=int (stoi(dd_chaine[3]));
  }
