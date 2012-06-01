#ifndef DEF_SAMOURAI
#define DEF_SAMOURAI

#include "ronin.hpp"

class samourai : public ronin
{
public :
  samourai(const char * nom, std::string s, int a) : ronin(nom,a),seigneur(s) {}
  samourai(const samourai&);
  samourai& operator=(const samourai&);
  virtual ~samourai();
  void action(humain*);
  std::string getAppartenance() {return seigneur;}
private :
  std::string seigneur;
};

#endif

