#ifndef _LALUNOS_H_
#define _LALUNOS_H_
#include "ElAluno.h"

class ListaAlunos {
private:
  int NumAlunos;
  int NumMaxAlunos;
  char nome[150];
  ElAluno *pElAlunoPrim;
  ElAluno *pElAlunoAtual;

public:
  ListaAlunos();
  ~ListaAlunos();
  void Inicializa(int NumMaxAlunosNa = 45, char nomeNa[] = "");
  void setNome(char nomeNa[] = "");
  char *getNome();
  void setNumMaxAlunos(int max = 45);
  int getNumMaxAlunos();
  int getNumAlunos();
  void incluaAluno(Aluno *aluno = NULL);
  void removaAluno(Aluno *aluno = NULL);
  void listeAlunos();
  void insertionsort();
};
#endif
