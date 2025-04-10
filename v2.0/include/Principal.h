#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_
#include "Pessoa.h"

class Principal{
private:
  Pessoa Simao;
  Pessoa Einstein;
  Pessoa Newton;
  Universidade UTFPR;
  Universidade Cambridge;
  Universidade Princeton;

  int diaA;
  int mesA;
  int anoA;

public:
  Principal();
  ~Principal();
  void Executar();
};


#endif
