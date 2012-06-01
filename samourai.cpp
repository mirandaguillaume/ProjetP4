#include "samourai.hpp"

using namespace std;

samourai::samourai(const samourai& s) : ronin(s.name,s.money,s.honneur), seigneur(s.seigneur) {}

samourai& samourai::operator=(const samourai& s)
{
  if (this!=&s)
    {
      if (name) delete [] name;
      name=new char [strlen(s.name)+1];
      strcpy(name,s.name);
      seigneur=s.seigneur;
      money=s.money;
      honneur=s.honneur;
    }
  return *this;
}

void samourai::action(humain* h)
{
  int choix=rand()%2;
  bool a=false;
  if(honneur>h->getAttrib())
    a=true;
  switch(choix)
    {
    case 0 : donner(h);break;
    case 1 : provoquer(h,a);break;
    }
}

samourai::~samourai()
{}
