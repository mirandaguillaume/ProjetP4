#include "humain.hpp"

humain::humain(const char* n, int m) : money(m), joue(false)
{
  name=new char [strlen(n)+1];
  strcpy(name,n);
}

humain::humain(const humain& h)
{
  name=new char[strlen(h.name)+1];
  strcpy(name,h.name);
  money=h.money;
  joue=h.joue;
}

std::string ToString(const int nb)
{
   std::ostringstream oss;
   oss << nb;
   return oss.str();
}

void humain::gagnerMoney(int i)
{
  money+=i;
  if (money>999)
    money=999;
}

void humain::perdreMoney(int i)
{
  money-=i;
  if (money<0) money=0;
}

humain& humain::operator = (const humain& h)
{
  if (this!=&h)
    {
      if (name) delete [] name;
      name=new char [strlen(h.name)+1];
      strcpy(name,h.name);
      money=h.money;
      joue=h.joue;
    }
  return *this;
}

humain::~humain()
{delete [] name;}
