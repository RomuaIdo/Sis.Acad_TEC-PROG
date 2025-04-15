#ifndef _ESTRELA_H_
#define _ESTRELA_H_
#include<stdio.h>
#include "Astro.h"
class Planeta;

class Estrela : public Astro{
private:
  int tempo_existencia;
  Planeta* pPlaneta;

public:
  Estrela();
  ~Estrela();
  void Inicializa(int tmp_ex = 0, Planeta*  pplaneta = NULL, int Na = 0);
  void setTempoExistencia(int tmp = 0);
  int getTempoExistencia();
};


#endif
