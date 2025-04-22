#ifndef _UNIVERSIDADE_H_  
#define _UNIVERSIDADE_H_
#include "Departamento/Departamento.h"
#include "Disciplina/Disciplina.h"

class ListaDepartamentos;
class Universidade{
private:
  char nome[100];
  ListaDepartamentos* ObjLDepartamentos;

public:
  Universidade();
  ~Universidade();
  void Inicializa(char* nomeNa = "");
  void setNome(char* nomeNa = "");
  char* getNome();
  void incluaDpto(Departamento* dpto = NULL);
  void removaDpto(Departamento* dpto = NULL);
  void listeDptos();
  void listeDptosComDisciplinas();
};

#endif
