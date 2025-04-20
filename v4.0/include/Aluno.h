#include "Pessoa.h"


class Aluno : public Pessoa {
private:
  int RA;
  Aluno* pProx;
  Aluno* pAnt;

public:
  Aluno();
  ~Aluno();
  void Inicializa(char nomeNa[] = "", int RA = -1, int dia = -1, int mes = -1, int ano = -1);
  void setRA(int Ra = -1);
  int getRA();
  void setProx(Aluno* prox);
  void setAnt(Aluno* ant);
  Aluno* getProx();
  Aluno* getAnt();
};
