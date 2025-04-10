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

  Departamento DAINF;
  Departamento DAELN;
  Departamento DAMAT;
  Departamento DAFIS;
  Departamento FisicaPrinceton;
  Departamento MatematicaCambridge;

  int diaA;
  int mesA;
  int anoA;

public:
  Principal();
  ~Principal();
  void Executar();
};


#endif
