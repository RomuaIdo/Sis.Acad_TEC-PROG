#include "../../include/Aluno/ElAluno.h"

ElAluno::ElAluno() { Inicializa(); }

ElAluno::~ElAluno() {
  aluno = NULL;
  pProx = NULL;
  pAnt = NULL;
}

void ElAluno::Inicializa(Aluno *alunoNa, int faltasNa) {
  setAluno(alunoNa);
  setProx(NULL);
  setAnt(NULL);
  setFaltas(faltasNa);
  for (int i = 0; i < 2; i++) {
    notas[i] = new Nota();
  }
}

Aluno *ElAluno::getAluno() { return aluno; }

ElAluno *ElAluno::getProx() { return pProx; }

ElAluno *ElAluno::getAnt() { return pAnt; }

void ElAluno::setProx(ElAluno *pProxNa) { pProx = pProxNa; }

void ElAluno::setAnt(ElAluno *pAntNa) { pAnt = pAntNa; }

void ElAluno::setAluno(Aluno *alunoNa) { aluno = alunoNa; }

void ElAluno::setFaltas(int faltasNa) { faltas = faltasNa; }

int ElAluno::getFaltas() { return faltas; }

void ElAluno::setNota(double notaNa, int cont) {
  if (cont >= 0 && cont < 2) {
    notas[cont]->setNota(notaNa);
  }
}

double ElAluno::getNota(int cont) {
  if (cont >= 0 && cont < 2) {
    return notas[cont]->getNota();
  }
  return -1.0;
}

void ElAluno::CalculaMediaFinal() {
  for (int i = 0; i < 2; i++) {
    if (notas[i]->getNota() < 0) {
      cout << "Erro: Avaliacao Pendente" << endl;
      return;
    }
  }
  mediafinal = (notas[0]->getNota() + notas[1]->getNota()) / 2;
}
