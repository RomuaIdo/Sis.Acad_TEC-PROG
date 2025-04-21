#ifndef _ELALUNO_H_
#define _ELALUNO_H_
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
#include "Nota.h"

class Aluno;
class ElAluno{
private:
  Aluno* aluno;
  ElAluno* pProx;
  ElAluno* pAnt;
  Nota *notas[2];
  double mediafinal;
  int faltas;

public:
  ElAluno();
  ~ElAluno();
  void Inicializa(Aluno* alunoNa = NULL, int faltasNa = 0);
  Aluno* getAluno();
  ElAluno* getProx();
  ElAluno* getAnt();
  void setProx(ElAluno* pProxNa = NULL);
  void setAnt(ElAluno* pAntNa = NULL);
  void setAluno(Aluno* alunoNa = NULL);
  void setFaltas(int faltasNa = 0);
  int getFaltas();
  void setNota(double notaNa, int cont);
  double getNota(int cont);
  void CalculaMediaFinal();
};


#endif
