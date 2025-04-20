#include "../include/Aluno.h"

Aluno::Aluno() {
  Pessoa::Inicializa();
  Inicializa();
}

Aluno::~Aluno() {}

void Aluno::Inicializa(char nomeNa[], int RA, int dia, int mes, int ano) {
  Pessoa::Inicializa(dia, mes, ano, nomeNa);
  setRA(RA);
}

void Aluno::setRA(int Ra) { RA = Ra; }

int Aluno::getRA() { return RA; }

void Aluno::setProx(Aluno* prox){ pProx =  prox; };
void Aluno::setAnt(Aluno* ant){ pAnt =  ant; };
Aluno *Aluno::getProx(){ return pProx; }
Aluno *Aluno::getAnt(){ return pAnt; }
