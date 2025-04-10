#include "../include/Principal.h"
#include <time.h>

Principal::Principal(){
  Simao.Inicializa(3, 10, 1976, "Simao");
  Einstein.Inicializa(14, 3, 1879, "Einstein");
  Newton.Inicializa(25, 12, 1642, "Newton");

  UTFPR.setNome("Universidade Tecnologica Federal do Parana");
  Cambridge.setNome("Universidade de Cambridge");
  Princeton.setNome("Universidade de Princeton");

  
  Simao.setUnivAfiliado(&UTFPR);
  Einstein.setUnivAfiliado(&Cambridge);
  Newton.setUnivAfiliado(&Princeton);

  struct tm *dataAtual;
  time_t segundos;
  time(&segundos);
  dataAtual = localtime(&segundos);

  diaA = dataAtual->tm_mday;
  mesA = dataAtual->tm_mon + 1;
  anoA = dataAtual->tm_year + 1900;
  Executar();
}

Principal::~Principal(){
}

void Principal::Executar(){
  Simao.CalculaIdade(diaA, mesA, anoA);
  Einstein.CalculaIdade(diaA, mesA, anoA);
  Newton.CalculaIdade(diaA, mesA, anoA);
  Simao.printIdade();
  Einstein.printIdade();
  Newton.printIdade();
  Simao.OndeTrabalho();
  Einstein.OndeTrabalho();
  Newton.OndeTrabalho();
}
