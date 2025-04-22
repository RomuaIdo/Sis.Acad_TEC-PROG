#include "../../include/Disciplina/LDisciplinas.h"
#include "../../include/Disciplina/ElDisciplina.h"
#include "../../include/Disciplina/Disciplina.h"


ListaDisciplinas::ListaDisciplinas() { Inicializa(); }

ListaDisciplinas::~ListaDisciplinas() {
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

void ListaDisciplinas::Inicializa(char nomeNa[]) {
  setNome(nomeNa);
  pElDisciplinaPrim = NULL;
  pElDisciplinaAtual = NULL;
}

void ListaDisciplinas::setNome(char nomeNa[]) { strcpy(nome, nomeNa); }

char *ListaDisciplinas::getNome() { return nome; }

void ListaDisciplinas::incluaDisciplina(Disciplina *pDisciplina) {
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

void ListaDisciplinas::listeDisciplinas() {
  ElDisciplina *paux = NULL;
  paux = pElDisciplinaPrim;
  while (paux != NULL) {
    cout << "A disciplina " << paux->getDisciplina()->getNome()
         << " pertence ao " << nome << endl;
    paux = paux->getProx();
  }
}

void ListaDisciplinas::removaDisciplina(Disciplina *pDisciplina) {
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

