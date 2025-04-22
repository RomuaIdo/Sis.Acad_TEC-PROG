#ifndef _ELDEPARTAMENTO_H_
#define _ELDEPARTAMENTO_H_
#include <stdio.h>
class Departamento;
class ElDepartamento{
private:
  Departamento* departamento;
  ElDepartamento* pProx;
  ElDepartamento* pAnt;

public:
  ElDepartamento();
  ~ElDepartamento();
  void Inicializa(Departamento* departamentoNa = NULL);
  Departamento* getDepartamento();
  ElDepartamento* getProx();
  ElDepartamento* getAnt();
  void setProx(ElDepartamento* pProxNa = NULL);
  void setAnt(ElDepartamento* pAntNa = NULL);
  void setDepartamento(Departamento* departamentoNa = NULL);
};

#endif
