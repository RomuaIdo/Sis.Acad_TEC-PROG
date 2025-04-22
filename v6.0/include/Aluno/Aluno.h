#ifndef _ALUNO_H_
#define _ALUNO_H_
#include "../Pessoa.h"


class Aluno : public Pessoa {
private:
  int RA;

public:
  Aluno();
  ~Aluno();
  void Inicializa(char nomeNa[] = "", int RA = -1, int dia = -1, int mes = -1, int ano = -1);
  void setRA(int Ra = -1);
  int getRA();
};

#endif
