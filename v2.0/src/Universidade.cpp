#include "../include/Universidade.h"
#include <string.h>

Universidade::Universidade(){
  Inicializa();
}
void Universidade::Inicializa(char* nomeNa){
  setNome(nomeNa);
}

Universidade::~Universidade(){
}

char* Universidade::getNome(){
  return nome;
}

void Universidade::setNome(char* nomeNa){
  strcpy(nome, nomeNa);
}
