#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_
#include "../Disciplina/LDisciplinas.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

class Universidade;
class Disciplina;
class ElDisciplina;

class Departamento {
private:
  int id;
  char nomeD[200];
  Universidade *pUniv;
  ListaDisciplinas *ObjLDisciplinas;

public:
  Departamento();
  ~Departamento();
  void Inicializa(char *nomeNa = "", Universidade *puni = NULL,
                  int idNa = -1);
  char *getNome();
  void setNome(char *nomeNa = "");
  void setUniversidade(Universidade *puni = NULL);
  Universidade *getUniversidade();
  void incluaDisciplina(Disciplina *pDisciplina = NULL);
  void listeDisciplinas();
  void removaDisciplina(Disciplina *pDisciplina = NULL);
  void setId(int idNa = -1);
  int getId();
};

#endif
