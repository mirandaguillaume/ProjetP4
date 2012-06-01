#ifndef DEF_RONIN
#define DEF_RONIN

#include "yakusa.hpp"
#include <cstdlib>
#include <ctime>
#include <cstring>

class ronin : public humain
{
public :
  virtual ~ronin();
  ronin(const char* n,int m,int honneur=1) : humain(n,m) , honneur(honneur) {}
  ronin(const ronin& r) : humain(r), honneur(r.honneur) {}
  ronin& operator=(const ronin& r);
  void donner(humain*);
  void provoquer(humain*,bool);
  virtual void action(humain*);
  int getAttrib() const {return honneur;}
  void direBonjour() const;
  void perdre();
  void gagner();
  virtual std::string getAppartenance() {return "";}
protected : 
  int honneur;
};

#endif
