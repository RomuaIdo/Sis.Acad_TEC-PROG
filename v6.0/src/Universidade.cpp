#include "../include/Universidade.h"
#include "../include/Departamento/ElDepartamento.h"
#include "../include/Departamento/LDepartamentos.h"
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

Universidade::Universidade() { Inicializa(); }
void Universidade::Inicializa(char *nomeNa) {
  ObjLDepartamentos = new ListaDepartamentos();
  setNome(nomeNa);
}

Universidade::~Universidade() {
  if (ObjLDepartamentos != NULL) {
    delete ObjLDepartamentos;
  }
  ObjLDepartamentos = NULL;
}

char *Universidade::getNome() { return nome; }

void Universidade::setNome(char *nomeNa) {
  strcpy(nome, nomeNa);
  ObjLDepartamentos->setNome(nomeNa);
}

void Universidade::incluaDpto(Departamento *dpto) {
  ObjLDepartamentos->incluaDpto(dpto);
  dpto->setUniversidade(this);
}

void Universidade::removaDpto(Departamento *dpto) {
  ObjLDepartamentos->removaDpto(dpto);
  dpto->setUniversidade(NULL);
  dpto = NULL;
}

void Universidade::listeDptos() {
  cout << "Departamentos da " << nome << ":" << endl;
  ObjLDepartamentos->listeDptos();
}

void Universidade::listeDptosComDisciplinas() {
  cout << "Departamentos da " << nome << ":" << endl;
  ObjLDepartamentos->listeDptosComDisciplinas();
}
