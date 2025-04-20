#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_
#include "Departamento.h"
#include <stdio.h>
#include <string.h>
class Aluno;

class Disciplina{
private:
  int id;
  char nome[150];
  char area_do_conhecimento[150];
  Departamento* pDptoAssociado;
  int NumMaxAlunos;
  int NumAlunos;
  Disciplina* pProx;
  Disciplina* pAnt;
  Aluno* pAlunoPrim;
  Aluno* pAlunoAtual;

public:
  Disciplina();
  ~Disciplina();
  void Inicializa(int idNa= -1, char nomeNa[] = "", char area_do_conhecimentoNA[] = "", Departamento* pDpto = NULL, int NumMaxAlunos = 45);
  void setId(int idNa=-1);
  int getId();
  void setNome(char nomeNa[] = "");
  char* getNome();
  void setDepartamento(Departamento* pDpto = NULL);
  Departamento* getDepartamento();
  void setArea_do_conhecimento(char area_do_conhecimentoNA[] = "");
  char* getArea_do_conhecimento();
  void setProx(Disciplina* prox = NULL);
  void setAnt(Disciplina* ant = NULL);
  Disciplina* getProx();
  Disciplina* getAnt();
  void setNumMaxAlunos(int max = 45);
  int getNumMaxAlunos();
  void setNumAlunos(int num = 0);
  int getNumAlunos();
  void incluaAluno(Aluno* aluno = NULL);
  void removaAluno(Aluno* aluno = NULL);
  void listeAlunos();
};

#endif
