#include "yakusa.hpp"

yakusa::yakusa(const char* n, std::string c, int m) : humain(n,m) , clan(c)
{reputation=rand()%3;} 

yakusa::yakusa(const yakusa& y) : humain(y)
{
  clan=y.clan;
  reputation=y.reputation;
}

yakusa& yakusa::operator=(const yakusa& y)
{
  if(name!=NULL) delete name;
  name=y.name;
  clan=y.clan;
  reputation=y.reputation;
  money=y.money;
  return *this;
}

void yakusa::extorquer(humain* h)
{
  reputation++;
  int i=h->getMoney();
  h->perdreMoney(i);
  gagnerMoney(i);
  std::string s(h->getName());
  parler("J'ai extorqué "+s+".");
}

yakusa::~yakusa()
{}

void yakusa::direBonjour() const
{
  std::string s(name);
  parler("Je m'appelle "+s+", j'ai "+ToString(money)+" euros, j'ai "+ToString(reputation)+" en réputation et j'appartient au clan "+clan+".");
}

void yakusa::gagner()
{
  parler("J'ai gagné le duel.");
  reputation++;
}

void yakusa::perdre()
{
  parler("J'ai perdu le duel.");
  reputation--;
  if (reputation<0)
    reputation=0;
}
