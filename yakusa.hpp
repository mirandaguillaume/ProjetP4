#ifndef DEF_YAKUSA
#define DEF_YAKUSA

#include "humain.hpp"
#include <ctime>
#include <cstdlib>

class yakusa : public humain
{
public :
  yakusa(const char* n,std::string c,int m);
  yakusa(const yakusa& y);
  void extorquer (humain* h);
  void action(humain* h){extorquer(h);}
  void gagner();
  void perdre();
  int getAttrib() const {return reputation;}
  std::string getClan() const {return clan;}
  void gagner () const;
  void perdre () const;
  yakusa& operator=(const yakusa& y);
  void direBonjour() const;
  virtual ~yakusa();
  std::string getAppartenance() {return clan;}
private :
  int reputation;
  std::string clan;
};

#endif 
