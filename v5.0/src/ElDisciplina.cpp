#include "../include/ElDisciplina.h"

ElDisciplina::ElDisciplina() { Inicializa(); }

ElDisciplina::~ElDisciplina() {
  pDisciplina = NULL;
  pProx = NULL;
  pAnt = NULL;
}

void ElDisciplina::Inicializa(Disciplina *pDisciplinaNa) {
  setDisciplina(pDisciplinaNa);
  setProx(NULL);
  setAnt(NULL);
}

void ElDisciplina::setProx(ElDisciplina *prox) { pProx = prox; }

ElDisciplina *ElDisciplina::getProx() { return pProx; }

void ElDisciplina::setAnt(ElDisciplina *ant) { pAnt = ant; }

ElDisciplina *ElDisciplina::getAnt() { return pAnt; }

Disciplina *ElDisciplina::getDisciplina() { return pDisciplina; }

void ElDisciplina::setDisciplina(Disciplina *pDisciplinaNa) {
  pDisciplina = pDisciplinaNa;
}
