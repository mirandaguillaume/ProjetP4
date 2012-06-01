#include "grille.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string randomPrenom()
{
  int nb;
  string junk,rep="";
  ifstream dictionnaire("Prenoms.txt");
  if (!dictionnaire)
    cout<<"Erreur dans l'ouverture du dictionnaire de noms!"<<endl;
  else
    {
      nb=rand()%11628;
      for (int i=0;i<nb-1;i++)
	getline(dictionnaire,junk);
      dictionnaire>>rep;
    }
  return rep;
}

void grille::init_matrice(humain* m[][5])
{
  for (int i=0;i<5;i++)
    for (int j=0;j<5;j++)
      m[i][j]=NULL;
}

grille::grille()
{
  int a,b,c;
  init_matrice(matrice);
  for (int i=0;i<((2*25)/3);i++)
    {
      do
	{
	  a=rand()%5;
	  b=rand()%5;
	} while(matrice[a][b]!=NULL);
      c=rand()%3;
      switch(c)
	{
	case 0 : matrice[a][b]=new yakusa(randomPrenom().c_str(),randomPrenom().c_str(),rand()%1000);break;
	case 1 : matrice[a][b]=new ronin(randomPrenom().c_str(),rand()%1000);break;
	case 2 : matrice[a][b]=new samourai(randomPrenom().c_str(),randomPrenom().c_str(),rand()%1000);break;
	}
    }
}

bool grille::AllPlayed()
{
  cout<<" ";
  for (int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      if (matrice[i][j]!=NULL)
	if (!matrice[i][j]->getJoue())
	  return false;
  return true;
}

void grille::deplacement()
{
  int i,j,cpt=0;
  while(!AllPlayed())
    {
      do 
	{
	  i=rand()%5;
	  j=rand()%5;
	} while(matrice[i][j]==NULL);
      if (!matrice[i][j]->getJoue())
	deplacer(i,j,cpt);
    }
  for (int i=0;i<5;i++)
    for (int j=0;j<5;j++)
      if (matrice[i][j]!=NULL)
	matrice[i][j]->setJoue(false);
}

void grille::deplacer_perso(int i,int j,int k, int l,int &cpt, bool &a)
{
  humain* h=NULL;
  bool b=false;
  if (matrice[k][l]!=NULL)
    b=matrice[k][l]->getJoue();
  if (!b)
    {
      if ((k!=5)&&(k!=-1)&&(l!=-1)&&(l!=5))
	{
	  cpt++;
	  cout<<endl<<cpt<<". ";
	  matrice[i][j]->direBonjour();
	  if (matrice[k][l]!=NULL)
	    {
	      cpt++;
	      h=matrice[k][l];
	      h->setJoue(true);
	      cout<<"Conflit avec "<<h->getName()<<endl;
	      cout<<cpt<<". ";
	      h->direBonjour();
	      matrice[i][j]->action(matrice[k][l]);
	    }
	  matrice[k][l]=matrice[i][j];
	  matrice[i][j]=h;
	  matrice[k][l]->setJoue(true);
	  cout<<"Déplacement en cours de "<<matrice[k][l]->getName()<<endl;
	  attendre();
	  cout<<endl<<endl;
	  a=true;
	}
    }
}

void grille::attendre()
{
  attente();
  affiche(cout);
}

void attente()
{
  cout<<"Appuyez sur Entree pour finir le déplacement..."<<endl;
  int i=getchar();
}

void grille::deplacer(int i,int j,int &cpt)
{
  bool a=false;
  int choix,k,l;
  do
    {
      choix=rand()%4;
      switch(choix)
	{
	case 0:	 k=i+1;l=j;break;
	case 1:  k=i-1;l=j;break;
	case 2:  k=i;l=j+1;break;
	case 3:  k=i;l=j-1;break;
	}
      deplacer_perso(i,j,k,l,cpt,a);
    } while(!a);
}				  

int grille::max_line(int i) const 
{
  int maxi=0;
  for (int j=0;j<5;j++)
    if (matrice[i][j]!=NULL)
      {
	maxi=max(maxi,(int)matrice[i][j]->getName().size());
	maxi=max(maxi,(int)matrice[i][j]->getAppartenance().size());
      }
  return maxi;
}

int grille::max_length() const 
{
  int maxi=0;
  for(int i=0;i<5;i++)
    maxi=max(maxi,max_line(i));
  return maxi;
}
			      
void grille::affiche(ostream& flux) const
{
  int a(0),b(0),c=max_length();
  if (c<3) c=3;
  for (int i=0;i<5;i++)
    {
      if (i==0) flux<<"╔"; else flux<<"╦";
      for (int j=0;j<c;j++)
	flux<<"═";
    }
  flux<<"╗"<<endl;
  for (int i=0;i<5;i++)
    {
      for (int j=0;j<5;j++)
	{
	  flux<<"║";
	  if(matrice[i][j]!=NULL)
	    {
	      flux<<matrice[i][j]->getName();
	      for (int x=0;x<c-matrice[i][j]->getName().size();x++)
		flux<<" ";
	    }
	  else 
	    {
	      for (int x=0;x<c;x++)
		flux<<" ";
	    }
	}
      flux<<"║"<<endl;
      for (int j=0;j<5;j++)
	{
	  flux<<"║";
	  if(matrice[i][j]!=NULL)
	    {
	      b=matrice[i][j]->getMoney();
	      flux<<b;
	      if (b<10) a=1;
	      else if (b<100) a=2;
	      else a=3;
	      for (int x=0;x<c-a;x++)
		flux<<" ";
	    }
	  else 
	    {
	      for (int x=0;x<c;x++)
		flux<<" ";
	    }
	}
      flux<<"║"<<endl;
      for (int j=0;j<5;j++)
	{
 	  flux<<"║";
	  if((matrice[i][j]!=NULL)&&(matrice[i][j]->getAppartenance()!=""))
	    {
	      flux<<matrice[i][j]->getAppartenance();
	      for (int x=0;x<c-matrice[i][j]->getAppartenance().size();x++)
		flux<<" ";
	    }
	  else 
	    {
	      for (int x=0;x<c;x++)
		flux<<" ";
	    }
	}
    flux<<"║"<<endl; 
      if (i<4)
	{
	  for (int j=0;j<5;j++)
	    {
	      if (j==0) flux<<"╠"; else flux<<"╬";
	      for (int x=0;x<c;x++)
		flux<<"═";
	    }
	  flux<<"╣"<<endl;
	}
    }
  for (int i=0;i<5;i++)
    {
      if (i==0) flux<<"╚"; else flux<<"╩";
      for (int j=0;j<c;j++)
	flux<<"═";
    }
  flux<<"╝"<<endl;
}

ostream& operator<<(ostream& flux,const grille& g)
{
  g.affiche(flux);
  return flux;
}
