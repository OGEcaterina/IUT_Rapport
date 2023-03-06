#ifndef CARTE_H
#define CARTE_H
#include <string>

using namespace std;

class Carte {
private:
  string _nom;  //nom de la carte
  int _atta;  //points d'attaque
  int _def;  //points de défense
  int _mag;  //points de puissance magique
public:
  ///constructeur vide
  Carte();
  ///Le constructeur avec les 4 arguments
  Carte(string nom, int att, int def, int mag);

  ///affiche les parametres de la carte en grand
  void afficher()const;
  ///affiche les parametres de la carte sur une ligne
  void afficherCourt()const;
  ///retourne les degats phisiques subis
  int degatPhysique (const Carte&)const;
  ///retourne les degats magiques subis
  int degatMagique(const Carte &)const;

  int getAtta()const;
  int getDef()const;
  int getMag()const;
  string getName()const;
  int Score()const;
  //void setStats(int att = 0, int def = 0, int mag = 0);
  //void permute(Carte& c2);
void remplir(const string & ligne );
};
//ostream & operator<<(ostream & ,  Carte&);
#endif // CARTE_H_INCLUDED
