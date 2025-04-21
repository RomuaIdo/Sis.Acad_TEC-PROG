#ifndef _PESSOA_H_
#define _PESSOA_H_
#include "Universidade.h"
#include<stdio.h>
#include<string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Pessoa{
private:
  int dia;
  int mes;
  int ano;
  int idade;
  char nomeP[100];

public:
  Pessoa();
  ~Pessoa();
  void Inicializa(int diaNa = 0, int mesNa = 0, int anoNa = 0, char* nomeNa = "");
  void CalculaIdade(int diaAtual, int mesAtual, int anoAtual);
  int getIdade();
  void printIdade();
  char* getNome();
  void setNome(char* nomeNa = "");
};


#endif
