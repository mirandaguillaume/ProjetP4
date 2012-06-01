#include <iostream>
#include "grille.hpp"

using namespace std;

void menu()
{
  int choix;
  grille g;
  cout<<"Bienvenue dans le RPG!"<<endl<<endl;
  cout<<"Entrez le nombre de tours requis (entrer 0 revient à quitter le jeu) : ";
  cin>>choix;
  for (int i=0;i<choix;i++)
    {
      cout<<"Tour n°"<<i+1<<endl;
      g.deplacement();
      cout<<endl<<"Appuyez sur Entree pour passer au tour suivant..."<<endl;
      int j=getchar();
    }
}

int main()
{
  srand(time(NULL));
  menu();
  return 0;
}


