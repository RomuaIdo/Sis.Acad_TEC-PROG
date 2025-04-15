#include "Estrela.h"
#ifndef _PLANETA_H_
#define _PLANETA_H_
#include "Astro.h"
#include<stdio.h>
#include<iostream>
using std::cout;
using std::endl;
class Planeta : public Astro {
private:
  int tempo_orbita;
  Estrela* pSol;

public:
  Planeta();
  ~Planeta();
  void Inicializa(int tmp_orb = 0, Estrela* ps = NULL, int na = 0);
  float CalculaQuantOrbita();
  void setTempoOrbita(int tmp = 0);
  void setSol(Estrela* pS = NULL);
};
#endif
