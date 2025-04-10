#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

class Universidade;

class Departamento{
private:
  char nomeD[200];
  Universidade* pUniv;

public:
  Departamento();
  ~Departamento();
  void Inicializa(char* nomeNa = "");
  char* getNome();
  void setNome(char* nomeNa = "");
  void setUniversidade(Universidade* puni);
};

#endif
