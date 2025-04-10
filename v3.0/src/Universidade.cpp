#include "../include/Universidade.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

Universidade::Universidade(){
  Inicializa();
}
void Universidade::Inicializa(char* nomeNa){
  setNome(nomeNa);
  for(int i = 0; i < 50; i++){
    pDpto[i] = NULL;
  }
}

Universidade::~Universidade(){
}

char* Universidade::getNome(){
  return nome;
}

void Universidade::setNome(char* nomeNa){
  strcpy(nome, nomeNa);
}

void Universidade::setDepartamento(Departamento* dpto, int ctd){
  pDpto[ctd] = dpto;
}

void Universidade::imprimeDptos(){
  cout << "Departamentos da " << nome << ":" << endl;
  for(int i = 0; i < 50; i++){
    if(pDpto[i] != NULL){
      cout << pDpto[i]->getNome() << endl;
    }
  }
}
