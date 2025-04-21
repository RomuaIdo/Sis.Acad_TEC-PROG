#ifndef _NOTA_H_
#define _NOTA_H_
#include <stdio.h>
#include <string.h>

class Nota{
private:
  //char* Descricao;
  double nota;
  //double peso;
public:
  Nota();
  ~Nota();
  void Inicializa(double notaNa = -1.0);
  //void setDescricao(char* DescricaoNa = "");
  //char* getDescricao();
  void setNota(double notaNa = 0.0);
  double getNota();
  //void setPeso(double pesoNa = 0.0);
  //double getPeso();
};
#endif
