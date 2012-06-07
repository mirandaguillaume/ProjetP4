#include "ronin.hpp"

ronin& ronin::operator=(const ronin& r)
{
  if (this!=&r)
    {
      if (name!=NULL) delete [] name;
      name=new char[strlen(r.name)+1];
      strcpy(name,r.name);
      honneur=r.honneur;
      money=r.money;
    }
  return *this;
}

ronin::~ronin()
{}

void ronin::donner(humain* h)
{
  std::string s(h->getName());
  int i;
  if (money!=0)
    i=rand()%(money+1);
  else 
    i=0;
  h->gagnerMoney(i);
  perdreMoney(i);
  parler("Tiens "+s+", voilà "+ToString(i)+" euros.");
}

void ronin::provoquer(humain* h,bool a)
{
  std::cout<<"Combat en cours"<<std::endl;
  int m;
  std::string s(h->getName());
  if (a)
    {
      honneur++;
      if (h->getMoney()!=0)
	m=rand()%(h->getMoney()+1);
      else 
	m=0;
      h->perdreMoney(m);
      gagnerMoney(m);
      h->perdre();
      parler("J'ai gagné le duel contre "+s+".");
    }
  else
    {
      honneur--;
      if (money!=0)
	m=rand()%(money+1);
      else
	m=0;
      h->gagnerMoney(m);
      perdreMoney(m);
      h->gagner();
      parler("J'ai perdu le duel contre "+s+".");
    }
}

void ronin::direBonjour() const
{
  std::string s(name),s1="Bonjour! Je m'appelle ";
  s1+=s;
  s1+=", j'ai "+ToString(money)+" euros en poche et "+ToString(honneur)+" pts d'honneur.";
  parler(s1);
}

void ronin::perdre()
{
  parler ("J'ai perdu le duel.");
  honneur--;
  if (honneur<0)
    honneur=0;
}

void ronin::gagner()
{
  parler ("J'ai gagné le duel.");
  honneur++;
}

void ronin::action(humain* h)
{
  int choix=rand()%2;
  bool a=false;
  if(2*honneur>h->getAttrib())
    a=true;
  switch(choix)
    {
    case 0 : donner(h);break;
    case 1 : provoquer(h,a);break;
    }
}
