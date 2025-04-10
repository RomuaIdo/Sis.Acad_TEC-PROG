#include "../include/Departamento.h"
#include<string.h>


Departamento::Departamento(){
  Inicializa();
}

Departamento::~Departamento(){
}

void Departamento::Inicializa(char* nomeNa){
  setNome(nomeNa);
  setUniversidade(0);
}

void Departamento::setNome(char* nomeNa){
  strcpy(nomeD, nomeNa);
}

char* Departamento::getNome(){
  return nomeD;
}

void Departamento::setUniversidade(Universidade* puni){
  pUniv = puni;
}
