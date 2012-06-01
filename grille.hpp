#ifndef DEF_GRILLE
#define DEF_GRILLE

#include "humain.hpp"
#include "ronin.hpp"
#include "yakusa.hpp"
#include "samourai.hpp"
#include <vector>
#include <ctime>
#include <cstring>
#include <cmath>

void attente();

class grille
{
public : 
  grille(); //done
  grille(const grille&); //How ?
  grille& operator= (const grille&); //How ?
  bool AllPlayed();
  void init_matrice(humain* m[][5]);
  void deplacement(); //done 
  void deplacer_perso(int,int,int,int,int&,bool&);
  void deplacer(int,int,int&); //done
  void afficher(); 
  int max_length() const;
  int max_line(int i) const;
  void attendre();
  void affiche(std::ostream&) const;
private :
  humain* matrice [5][5];
};

std::ostream& operator<<(std::ostream& flux,const grille& g);

#endif
