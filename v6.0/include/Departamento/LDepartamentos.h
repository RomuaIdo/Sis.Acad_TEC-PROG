#ifndef _LDEPARTAMENTO_H_
#define _LDEPARTAMENTO_H_
#include <stdio.h>

class Departamento;
class ElDepartamento;
class ListaDepartamentos{
private:
  char nome[200];
  ElDepartamento *pElDepartamentoPrim;
  ElDepartamento *pElDepartamentoAtual;

public:
  ListaDepartamentos();
  ~ListaDepartamentos();
  void Inicializa(char nomeNa[] = "");
  void setNome(char nomeNa[]);
  char *getNome();
  void incluaDpto(Departamento *pDepartamento = NULL);
  void removaDpto(Departamento *pDepartamento = NULL);
  void listeDptos();
  void listeDptosComDisciplinas();
};


#endif
