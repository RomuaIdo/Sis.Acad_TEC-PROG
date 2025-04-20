#include "../include/Universidade.h"
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

Universidade::Universidade() { Inicializa(); }
void Universidade::Inicializa(char *nomeNa) {
  setNome(nomeNa);
  for (int i = 0; i < 50; i++) {
    pDpto[i] = NULL;
  }
}

Universidade::~Universidade() {}

char *Universidade::getNome() { return nome; }

void Universidade::setNome(char *nomeNa) { strcpy(nome, nomeNa); }

void Universidade::setDepartamento(Departamento *dpto, int ctd) {
  pDpto[ctd] = dpto;
  dpto->setUniversidade(this);
}

void Universidade::imprimeDptos() {
  cout << "Departamentos da " << nome << ":" << endl;
  for (int i = 0; i < 50; i++) {
    if (pDpto[i] != NULL) {
      cout << pDpto[i]->getNome() << endl;
    }
  }
}

void Universidade::imprimeDptosComDisciplinas() {
  cout << "Departamentos da " << nome << ":" << endl;
  for (int i = 0; i < 50; i++) {
    if (pDpto[i] != NULL) {
      cout << pDpto[i]->getNome() << endl;
      pDpto[i]->listeDisciplinas();
    }
  }
}
