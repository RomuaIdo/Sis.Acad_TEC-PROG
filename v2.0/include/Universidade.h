#ifndef _UNIVERSIDADE_H_  
#define _UNIVERSIDADE_H_

class Universidade{
private:
  char nome[100];

public:
  Universidade();
  ~Universidade();
  void Inicializa(char* nomeNa = "");
  void setNome(char* nomeNa = "");
  char* getNome();
};

#endif
