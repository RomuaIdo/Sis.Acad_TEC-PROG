#include "../../include/Departamento/LDepartamentos.h"
#include "../../include/Departamento/ElDepartamento.h"
#include "../../include/Departamento/Departamento.h"

ListaDepartamentos::ListaDepartamentos() { Inicializa(); }

ListaDepartamentos::~ListaDepartamentos() {
  if (pElDepartamentoPrim != NULL) {
    ElDepartamento *paux = NULL;
    paux = pElDepartamentoPrim;
    while (paux != NULL) {
      ElDepartamento *paux2 = NULL;
      paux2 = paux->getProx();
      delete paux;
      paux = paux2;
    }
  }
  pElDepartamentoPrim = NULL;
  pElDepartamentoAtual = NULL;
}

void ListaDepartamentos::Inicializa(char nomeNa[]) {
  setNome(nomeNa);
  pElDepartamentoPrim = NULL;
  pElDepartamentoAtual = NULL;
}

void ListaDepartamentos::setNome(char nomeNa[]) { strcpy(nome, nomeNa); }

char *ListaDepartamentos::getNome() { return nome; }

void ListaDepartamentos::incluaDpto(Departamento *pDepartamento) {
  ElDepartamento *pElDepartamento = NULL;
  pElDepartamento = new ElDepartamento();
  pElDepartamento->setDepartamento(pDepartamento);
  if (pElDepartamentoPrim == NULL) {
    pElDepartamentoPrim = pElDepartamento;
    pElDepartamentoAtual = pElDepartamento;
    pElDepartamentoAtual->setProx(NULL);
    pElDepartamentoAtual->setAnt(NULL);
  } else if (pDepartamento != NULL) {
    pElDepartamento->setAnt(pElDepartamentoAtual);
    pElDepartamentoAtual->setProx(pElDepartamento);
    pElDepartamentoAtual = pElDepartamento;
    pElDepartamentoAtual->setProx(NULL);
  } else {
    cout << "Erro: departamento nulo!" << endl;
  }
}

void ListaDepartamentos::listeDptos() {
  ElDepartamento *paux = NULL;
  paux = pElDepartamentoPrim;
  while (paux != NULL) {
    cout << "O departamento " << paux->getDepartamento()->getNome()
         << " pertence a universidade " << getNome() << endl;
    paux = paux->getProx();
  }
}

void ListaDepartamentos::listeDptosComDisciplinas() {
  ElDepartamento *paux = NULL;
  paux = pElDepartamentoPrim;
  while (paux != NULL) {
    cout << "O departamento " << paux->getDepartamento()->getNome()
         << " pertence a universidade " << nome << endl;
    paux->getDepartamento()->listeDisciplinas();
    paux = paux->getProx();
  }
}

void ListaDepartamentos::removaDpto(Departamento *pDepartamento) {
   if (pDepartamento == NULL) {
    cout << "Erro: departamento nulo!" << endl;
    return;
  } else if (pElDepartamentoPrim == NULL) {
    cout << "Erro: lista de departamentos vazia!" << endl;
    return;
  } else {

    ElDepartamento *paux = NULL;
    paux = pElDepartamentoPrim;
    while (paux != NULL && paux->getDepartamento() != pDepartamento) {
      paux = paux->getProx();
    }
    if (paux == NULL) {
      cout << "Erro: Departamento nao encontrado!" << endl;
      return;
    } else {
      if (paux == pElDepartamentoPrim) {
        pElDepartamentoPrim = paux->getProx();
        if (pElDepartamentoPrim != NULL) {
          pElDepartamentoPrim->setAnt(NULL);
        }
      } else if (paux == pElDepartamentoAtual) {
        pElDepartamentoAtual = paux->getAnt();
        if (pElDepartamentoAtual != NULL) {
          pElDepartamentoAtual->setProx(NULL);
        }
      } else {
        paux->getAnt()->setProx(paux->getProx());
        paux->getProx()->setAnt(paux->getAnt());
      }
    }
    delete paux;
  }
}


