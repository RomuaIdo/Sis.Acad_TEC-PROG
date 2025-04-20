#ifndef _UNIVERSIDADE_H_  
#define _UNIVERSIDADE_H_
#include "Departamento.h"
#include "Disciplina.h"

class Universidade{
private:
  char nome[100];
  Departamento* pDpto[50];

public:
  Universidade();
  ~Universidade();
  void Inicializa(char* nomeNa = "");
  void setNome(char* nomeNa = "");
  char* getNome();
  void setDepartamento(Departamento* dpto, int ctd);
  void imprimeDptos();
  void imprimeDptosComDisciplinas();
};

#endif
