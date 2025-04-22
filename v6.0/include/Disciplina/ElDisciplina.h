#ifndef _ELDISCIPLINA_H_
#define _ELDISCIPLINA_H_
#include "Disciplina.h"


class ElDisciplina {
private:
  Disciplina *pDisciplina;
  ElDisciplina *pProx;
  ElDisciplina *pAnt;

public:
  ElDisciplina();
  ~ElDisciplina();
  void Inicializa(Disciplina *pDisciplinaNa = NULL);
  void setProx(ElDisciplina *prox = NULL);
  ElDisciplina *getProx();
  void setAnt(ElDisciplina *ant = NULL);
  ElDisciplina *getAnt();
  Disciplina *getDisciplina();
  void setDisciplina(Disciplina *pDisciplinaNa = NULL);
};
#endif
