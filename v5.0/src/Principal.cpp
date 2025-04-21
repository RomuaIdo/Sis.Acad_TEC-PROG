#include "../include/Principal.h"
#include <time.h>

Principal::Principal() {
  struct tm *dataAtual;
  time_t segundos;
  time(&segundos);
  dataAtual = localtime(&segundos);

  diaA = dataAtual->tm_mday;
  mesA = dataAtual->tm_mon + 1;
  anoA = dataAtual->tm_year + 1900;
  Inicializa();
  Executa();
}

Principal::~Principal() {}

void Principal::Inicializa() {
  InicializaUniversidades();
  InicializaDepartamentos();
  InicializaProfessores();
  InicializaDisciplinas();
}

void Principal::InicializaUniversidades() {
  UTFPR.setNome("Universidade Tecnologica Federal do Parana");
  Cambridge.setNome("Universidade de Cambridge");
  Princeton.setNome("Universidade de Princeton");
}

void Principal::InicializaDepartamentos() {
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
}

void Principal::InicializaProfessores() {
  Simao.setNome("Simao");
  Einstein.setNome("Einstein");
  Newton.setNome("Newton");

  Simao.setUnivAfiliado(&UTFPR);
  Einstein.setUnivAfiliado(&Cambridge);
  Newton.setUnivAfiliado(&Princeton);

  Simao.setDptoAfiliado(&DAINF);
  Einstein.setDptoAfiliado(&MatematicaCambridge);
  Newton.setDptoAfiliado(&FisicaPrinceton);
}

void Principal::InicializaDisciplinas() {
  Fundamentos_de_Programacao1.setNome("Fundamentos de Programacao 1");
  Estruturas_de_Dados1.setNome("Estruturas de Dados 1");
  Tecnicas_de_Programacao.setNome("Tecnicas de Programacao");
  Calculo1.setNome("Calculo 1");
  Oficinas_de_Integracao.setNome("Oficinas de Integracao");
  Fisica1.setNome("Fisica 1");
  Mecanica_Newtoniana.setNome("Mecanica Newtoniana");
  Teoria_dos_numeros.setNome("Teoria dos numeros");
  // Adiciona disciplinas aos departamentos
  // DAINF
  Fundamentos_de_Programacao1.setDepartamento(&DAINF);
  Estruturas_de_Dados1.setDepartamento(&DAINF);
  Tecnicas_de_Programacao.setDepartamento(&DAINF);
  // DAMAT
  Calculo1.setDepartamento(&DAMAT);
  // DAELN
  Oficinas_de_Integracao.setDepartamento(&DAELN);
  // DAFIS
  Fisica1.setDepartamento(&DAFIS);
  // FisicaPrinceton
  Mecanica_Newtoniana.setDepartamento(&FisicaPrinceton);
  // MatematicaCambridge
  Teoria_dos_numeros.setDepartamento(&MatematicaCambridge);

  // Adiciona alunos as disciplinas
  aluno1.Inicializa("Lirili Larila", 123456, 1, 1, 2000);
  aluno2.Inicializa("Tralalero Tralala", 123457, 1, 1, 2000);
  aluno3.Inicializa("Trulimero Trulicina", 123458, 1, 1, 2000);
  aluno4.Inicializa("Bombardilo Crocodilo", 123459, 1, 1, 2000);
  aluno5.Inicializa("Tung Tung Tung Sahur", 123460, 1, 1, 2000);
  Tecnicas_de_Programacao.incluaAluno(&aluno5);
  Tecnicas_de_Programacao.incluaAluno(&aluno4);
  Tecnicas_de_Programacao.incluaAluno(&aluno3);
  Tecnicas_de_Programacao.incluaAluno(&aluno2);
  Tecnicas_de_Programacao.incluaAluno(&aluno1);
  Fundamentos_de_Programacao1.incluaAluno(&aluno1);
  Fundamentos_de_Programacao1.incluaAluno(&aluno2);
  Fundamentos_de_Programacao1.incluaAluno(&aluno3);
  Fundamentos_de_Programacao1.incluaAluno(&aluno5);
}

void Principal::CalculaIdadeProfs() {
  Simao.CalculaIdade(diaA, mesA, anoA);
  Einstein.CalculaIdade(diaA, mesA, anoA);
  Newton.CalculaIdade(diaA, mesA, anoA);
}

void Principal::UnivOndeProfsTrabalham() {
  Simao.OndeTrabalho();
  Einstein.OndeTrabalho();
  Newton.OndeTrabalho();
}

void Principal::DptoOndeProfsTrabalham() {
  Simao.QualDepartamentoTrabalho();
  Einstein.QualDepartamentoTrabalho();
  Newton.QualDepartamentoTrabalho();
}

void Principal::ListeDiscDptos() {
  UTFPR.imprimeDptosComDisciplinas();
  Princeton.imprimeDptosComDisciplinas();
  Cambridge.imprimeDptosComDisciplinas(); 
}

void Principal::ListeAlunosDisc() {
  Tecnicas_de_Programacao.listeAlunos();
  Fundamentos_de_Programacao1.listeAlunos();
  Estruturas_de_Dados1.listeAlunos();
  Calculo1.listeAlunos();
  Oficinas_de_Integracao.listeAlunos();
  Fisica1.listeAlunos();
  Mecanica_Newtoniana.listeAlunos();
  Teoria_dos_numeros.listeAlunos();
}

void Principal::Executa() {
  CalculaIdadeProfs();
  Simao.printIdade();
  Einstein.printIdade();
  Newton.printIdade();
  UnivOndeProfsTrabalham();
  DptoOndeProfsTrabalham();
  ListeDiscDptos();
  ListeAlunosDisc();
}
