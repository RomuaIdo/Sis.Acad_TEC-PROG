#include<stdio.h>

#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

class Pessoa{
private:
  int dia;
  int mes;
  int ano;
  int idade;

public:
  Pessoa(int diaNa, int mesNa, int anoNa);
  void CalculaIdade(int diaAtual, int mesAtual, int anoAtual);
  int getIdade();
  void printIdade();
};


#endif
