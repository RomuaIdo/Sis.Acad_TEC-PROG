#include "../include/Departamento.h"
#include "../include/Disciplina.h"
#include <string.h>

Departamento::Departamento() { Inicializa(); }

Departamento::~Departamento() {}

void Departamento::Inicializa(char *nomeNa, Universidade *puni,
                              Disciplina *pDisciplina, int idNa) {
  setId(-1);
  setNome(nomeNa);
  setUniversidade(puni);
  pDisciplinaPrim = pDisciplina;
  pDisciplinaAtual = pDisciplina;
}

void Departamento::setNome(char *nomeNa) { strcpy(nomeD, nomeNa); }

char *Departamento::getNome() { return nomeD; }

void Departamento::setUniversidade(Universidade *puni) { pUniv = puni; }

Universidade *Departamento::getUniversidade() { return pUniv; }

void Departamento::incluaDisciplina(Disciplina *pDisciplina) {
  if (pDisciplinaPrim == NULL) {
    pDisciplinaPrim = pDisciplina;
    pDisciplinaAtual = pDisciplina;
    pDisciplinaAtual->setProx(NULL);
    pDisciplinaAtual->setAnt(NULL);
  } else if (pDisciplina != NULL) {
    pDisciplina->setAnt(pDisciplinaAtual);
    pDisciplinaAtual->setProx(pDisciplina);
    pDisciplinaAtual = pDisciplina;
    pDisciplinaAtual->setProx(NULL);
  } else {
    cout << "Erro: disciplina nula!" << endl;
  }
}

void Departamento::listeDisciplinas() {
  Disciplina *paux = NULL;
  paux = pDisciplinaPrim;
  while (paux != NULL) {
    cout << "A disciplina " << paux->getNome() << " pertence ao " << getNome()
         << endl;
    paux = paux->getProx();
  }
}

void Departamento::removaDisciplina(Disciplina *pDisciplina) {
  if (pDisciplina == NULL) {
    cout << "Erro: disciplina nula!" << endl;
    return;
  } else if (pDisciplinaPrim == NULL) {
    cout << "Erro: lista de disciplinas vazia!" << endl;
    return;
  } else {

    Disciplina *paux = NULL;
    paux = pDisciplinaPrim;
    while (paux != NULL && paux != pDisciplina) {
      paux = paux->getProx();
    }
    if (paux == NULL) {
      cout << "Erro: disciplina nao encontrada!" << endl;
      return;
    } else {
      if (paux == pDisciplinaPrim) {
        pDisciplinaPrim = paux->getProx();
        if (pDisciplinaPrim != NULL) {
          pDisciplinaPrim->setAnt(NULL);
        }
      } else if (paux == pDisciplinaAtual) {
        pDisciplinaAtual = paux->getAnt();
        if (pDisciplinaAtual != NULL) {
          pDisciplinaAtual->setProx(NULL);
        }
      } else {
        paux->getAnt()->setProx(paux->getProx());
        paux->getProx()->setAnt(paux->getAnt());
      }
    }
  }
}
void Departamento::setId(int idNa) { id = idNa; }
int Departamento::getId() { return id; }
