#include "../include/Principal.h"
#include <time.h>

Principal::Principal(){
  Simao.Inicializa(3, 10, 1976, "Simao");
  Einstein.Inicializa(14, 3, 1879, "Einstein");
  Newton.Inicializa(25, 12, 1642, "Newton");

  UTFPR.setNome("Universidade Tecnologica Federal do Parana");
  Cambridge.setNome("Universidade de Cambridge");
  Princeton.setNome("Universidade de Princeton");

  DAINF.setNome("Departamento Academico de Informatica");
  DAELN.setNome("Departamento Academico de Eletronica");
  DAMAT.setNome("Departamento Academico de Matematica");
  DAFIS.setNome("Departamento Academico de Fisica");
  FisicaPrinceton.setNome("Departamento de Fisica de Princeton");
  MatematicaCambridge.setNome("Departamento de Matematica de Cambridge");
  
  UTFPR.setDepartamento(&DAINF, 0);
  UTFPR.setDepartamento(&DAELN, 1);
  UTFPR.setDepartamento(&DAMAT, 2);
  UTFPR.setDepartamento(&DAFIS, 3);
  Princeton.setDepartamento(&FisicaPrinceton, 0);
  Cambridge.setDepartamento(&MatematicaCambridge, 0);

  DAINF.setUniversidade(&UTFPR);
  DAELN.setUniversidade(&UTFPR);
  DAMAT.setUniversidade(&UTFPR);
  DAFIS.setUniversidade(&UTFPR);
  FisicaPrinceton.setUniversidade(&Princeton);
  MatematicaCambridge.setUniversidade(&Cambridge);


  Simao.setUnivAfiliado(&UTFPR);
  Einstein.setUnivAfiliado(&Cambridge);
  Newton.setUnivAfiliado(&Princeton);

  Simao.setDptoAfiliado(&DAINF);
  Einstein.setDptoAfiliado(&MatematicaCambridge);
  Newton.setDptoAfiliado(&FisicaPrinceton);

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
  Simao.QualDepartamentoTrabalho();
  Einstein.QualDepartamentoTrabalho();
  Newton.QualDepartamentoTrabalho();
  UTFPR.imprimeDptos();
  Princeton.imprimeDptos();
  Cambridge.imprimeDptos();
}
