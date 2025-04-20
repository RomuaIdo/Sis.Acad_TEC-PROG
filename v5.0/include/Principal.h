#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_
#include "Professor.h"
#include "Aluno.h"

class Principal{
private:
  // Professores
  Professor Simao;
  Professor Einstein;
  Professor Newton;

  // Universidades
  Universidade UTFPR;
  Universidade Cambridge;
  Universidade Princeton;

  //Departamentos
  Departamento DAINF;
  Departamento DAELN;
  Departamento DAMAT;
  Departamento DAFIS;
  Departamento FisicaPrinceton;
  Departamento MatematicaCambridge;

  // Disciplinas
  Disciplina Fundamentos_de_Programacao1;
  Disciplina Estruturas_de_Dados1;
  Disciplina Tecnicas_de_Programacao;
  Disciplina Calculo1;
  Disciplina Oficinas_de_Integracao;
  Disciplina Fisica1;
  Disciplina Mecanica_Newtoniana;
  Disciplina Teoria_dos_numeros;
  
  // Alunos
  Aluno aluno1;
  Aluno aluno2;
  Aluno aluno3;
  Aluno aluno4;
  Aluno aluno5;
  // Data atual
  int diaA;
  int mesA;
  int anoA;

public:
  Principal();
  ~Principal();

  //Inicializacoes
  void Inicializa();
  void InicializaUniversidades();
  void InicializaDepartamentos();
  void InicializaProfessores();
  void InicializaDisciplinas();

  void Executa();

  void CalculaIdadeProfs();
  void UnivOndeProfsTrabalham();
  void DptoOndeProfsTrabalham();
  void ListeDiscDptos();
  void ListeAlunosDisc();
};


#endif
