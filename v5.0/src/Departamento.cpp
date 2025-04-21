#include "../include/Departamento.h"
#include "../include/Disciplina.h"
#include "../include/ElDisciplina.h"
#include <string.h>

Departamento::Departamento() { Inicializa(); }

Departamento::~Departamento() {
  if (pUniv != NULL) {
    pUniv = NULL;
  }
  if (pElDisciplinaPrim != NULL) {
    ElDisciplina *paux = NULL;
    paux = pElDisciplinaPrim;
    while (paux != NULL) {
      ElDisciplina *paux2 = NULL;
      paux2 = paux->getProx();
      delete paux;
      paux = paux2;
    }
  }
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
}

void Departamento::Inicializa(char *nomeNa, Universidade *puni, int idNa) {
  setId(-1);
  setNome(nomeNa);
  setUniversidade(puni);
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
}

void Departamento::setNome(char *nomeNa) { strcpy(nomeD, nomeNa); }

char *Departamento::getNome() { return nomeD; }

void Departamento::setUniversidade(Universidade *puni) { pUniv = puni; }

Universidade *Departamento::getUniversidade() { return pUniv; }

void Departamento::incluaDisciplina(Disciplina *pDisciplina) {
  ElDisciplina *pElDisciplina = NULL;
  pElDisciplina = new ElDisciplina();
  pElDisciplina->setDisciplina(pDisciplina);
  if (pElDisciplinaPrim == NULL) {
    pElDisciplinaPrim = pElDisciplina;
    pElDisciplinaAtual = pElDisciplina;
    pElDisciplinaAtual->setProx(NULL);
    pElDisciplinaAtual->setAnt(NULL);
  } else if (pDisciplina != NULL) {
    pElDisciplina->setAnt(pElDisciplinaAtual);
    pElDisciplinaAtual->setProx(pElDisciplina);
    pElDisciplinaAtual = pElDisciplina;
    pElDisciplinaAtual->setProx(NULL);
  } else {
    cout << "Erro: disciplina nula!" << endl;
  }
}

void Departamento::listeDisciplinas() {
  ElDisciplina *paux = NULL;
  paux = pElDisciplinaPrim;
  while (paux != NULL) {
    cout << "A disciplina " << paux->getDisciplina()->getNome()
         << " pertence ao " << getNome() << endl;
    paux = paux->getProx();
  }
}

void Departamento::removaDisciplina(Disciplina *pDisciplina) {
  if (pDisciplina == NULL) {
    cout << "Erro: disciplina nula!" << endl;
    return;
  } else if (pElDisciplinaPrim == NULL) {
    cout << "Erro: lista de disciplinas vazia!" << endl;
    return;
  } else {

    ElDisciplina *paux = NULL;
    paux = pElDisciplinaPrim;
    while (paux != NULL && paux->getDisciplina() != pDisciplina) {
      paux = paux->getProx();
    }
    if (paux == NULL) {
      cout << "Erro: disciplina nao encontrada!" << endl;
      return;
    } else {
      if (paux == pElDisciplinaPrim) {
        pElDisciplinaPrim = paux->getProx();
        if (pElDisciplinaPrim != NULL) {
          pElDisciplinaPrim->setAnt(NULL);
        }
      } else if (paux == pElDisciplinaAtual) {
        pElDisciplinaAtual = paux->getAnt();
        if (pElDisciplinaAtual != NULL) {
          pElDisciplinaAtual->setProx(NULL);
        }
      } else {
        paux->getAnt()->setProx(paux->getProx());
        paux->getProx()->setAnt(paux->getAnt());
      }
    }
    delete paux;
  }
}
void Departamento::setId(int idNa) { id = idNa; }
int Departamento::getId() { return id; }
