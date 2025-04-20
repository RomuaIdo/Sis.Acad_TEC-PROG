#include "../include/Pessoa.h"

Pessoa::Pessoa() { Inicializa(); }
Pessoa::~Pessoa() {}

void Pessoa::Inicializa(int diaNa, int mesNa, int anoNa, char *nomeNa) {
  dia = diaNa;
  mes = mesNa;
  ano = anoNa;
  idade = 0;
  strcpy(nomeP, nomeNa);
}

void Pessoa::CalculaIdade(int diaAtual, int mesAtual, int anoAtual) {
  idade = anoAtual - ano;
  if (mesAtual < mes || (mesAtual == mes && diaAtual < dia)) {
    idade--;
  }
}
int Pessoa::getIdade() { return idade; }
void Pessoa::printIdade() {
  cout << "Idade de " << nomeP << ": " << idade << endl;
}

char *Pessoa::getNome() { return nomeP; }

void Pessoa::setNome(char *nomeNa) { strcpy(nomeP, nomeNa); }

