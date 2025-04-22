#ifndef _LDISCIPLINA_H_
#define _LDISCIPLINA_H_
#include <stdio.h>

class ElDisciplina;
class Disciplina;
class ListaDisciplinas {
private:
  char nome[200];
  ElDisciplina *pElDisciplinaPrim;
  ElDisciplina *pElDisciplinaAtual;

public:
  ListaDisciplinas();
  ~ListaDisciplinas();
  void Inicializa(char nomeNa[] = "");
  void setNome(char nomeNa[] = "");
  char *getNome();
  void incluaDisciplina(Disciplina *pDisciplina = NULL);
  void removaDisciplina(Disciplina *pDisciplina = NULL);
  void listeDisciplinas();
};


#endif
