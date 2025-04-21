#include "../include/Nota.h"


Nota::Nota() { Inicializa(); }

Nota::~Nota() {
  /*if (Descricao != NULL) {
    delete[] Descricao;
  }*/
  //Descricao = NULL;
  //peso = 0.0;
  nota = 0.0;
}

void Nota::Inicializa(double notaNa) {
  /*Descricao = new char[strlen(DescricaoNa) + 1];
  strcpy(Descricao, DescricaoNa);*/
  nota = notaNa;
  //peso = pesoNa;
}

/*void Nota::setDescricao(char* DescricaoNa) {
  if (Descricao != NULL) {
    delete[] Descricao;
  }
  Descricao = new char[strlen(DescricaoNa) + 1];
  strcpy(Descricao, DescricaoNa);
}

char* Nota::getDescricao() { return Descricao; }
*/
void Nota::setNota(double notaNa) { nota = notaNa; }

double Nota::getNota() { return nota; }

/*void Nota::setPeso(double pesoNa) { peso = pesoNa; }

double Nota::getPeso() { return peso; }
*/
