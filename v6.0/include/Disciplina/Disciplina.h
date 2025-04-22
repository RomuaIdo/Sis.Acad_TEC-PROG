#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_
#include "../Aluno/LAlunos.h"
#include <stdio.h>
#include <string.h>

class Aluno;
class Departamento;

class Disciplina {
private:
  int id;
  char nome[150];
  char area_do_conhecimento[150];
  Departamento *pDptoAssociado;
  int AulasSemanais;
  double media;
  ListaAlunos ObjLAlunos;

public:
  Disciplina();
  ~Disciplina();
  void Inicializa(int idNa = -1, char nomeNa[] = "",
                  char area_do_conhecimentoNA[] = "",
                  Departamento *pDpto = NULL, int AulasSemanais = 0,
                  double media = 6.0);
  void setId(int idNa = -1);
  int getId();
  void setAulasSemanais(int AulasSemanaisNa = 0);
  int getAulasSemanais();
  void setNome(char nomeNa[] = "");
  char *getNome();
  void setDpto(Departamento *pDpto = NULL);
  Departamento *getDepartamento();
  void setArea_do_conhecimento(char area_do_conhecimentoNA[] = "");
  char *getArea_do_conhecimento();
  int getNumMaxAlunos();
  void setNumMaxAlunos(int NumMaxAlunosNa = 45);
  int getNumAlunos();
  void setMedia(double mediaNa = 6.0);
  double getMedia();
  void incluaAluno(Aluno *aluno);
  void removaAluno(Aluno *aluno);
  void listeAlunos();
};

#endif
