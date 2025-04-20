#include "../include/Professor.h"

Professor::Professor() { Inicializa(); }

Professor::~Professor() {}

void Professor::Inicializa(int diaNa, int mesNa, int anoNa, char* nomeNa,
                            Universidade* pUnivAfiliado,
                            Departamento* pDptoAfiliado) {
  Pessoa::Inicializa(diaNa, mesNa, anoNa, nomeNa);
  setUnivAfiliado(pUnivAfiliado);
  setDptoAfiliado(pDptoAfiliado);
}

void Professor::setUnivAfiliado(Universidade* pUniv) {
  pUnivAfiliado = pUniv;
}

Universidade* Professor::getUnivAfiliado() { return pUnivAfiliado; }

void Professor::setDptoAfiliado(Departamento* pdep) {
  pDptoAfiliado = pdep;
}

Departamento* Professor::getDptoAfiliado() { return pDptoAfiliado; }

void Professor::OndeTrabalho() {
  cout << Pessoa::getNome() << " trabalha para a " << pUnivAfiliado->getNome() << endl;
}

void Professor::QualDepartamentoTrabalho() {
  cout << Pessoa::getNome() << " trabalha no " << pDptoAfiliado->getNome() << endl;
}

