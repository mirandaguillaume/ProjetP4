#ifndef DEF_HUMAIN
#define DEF_HUMAIN

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <cstring>

std::string ToString(const int n);

class humain
{
public :
  virtual ~humain();
  humain(const char* n,int m);
  humain(const humain& h);
  void parler(std::string texte) const {std::cout<<name<<" - "<<texte<<std::endl;}
  int getMoney() const {return money;}
  virtual void direBonjour() const =0;
  std::string getName() const {return name;}
  virtual int getAttrib() const =0;
  virtual std::string getAppartenance() =0;
  void gagnerMoney(int i);
  void perdreMoney(int i);
  virtual void perdre()=0;
  virtual void gagner()=0;
  humain& operator=(const humain& h);
  virtual void action(humain*) =0;
  bool getJoue() {return joue;}
  void setJoue(bool a) {joue=a;}
protected :
  char * name;
  int money;
  bool joue;
};

#endif

