#ifndef _SISTEMASOLAR_H_
#define _SISTEMASOLAR_H_
#include "Estrela.h"
#include "Planeta.h"

class SistemaSolar{
private:
  Estrela Sol;
  Planeta Jupiter;

public:
  SistemaSolar();
  ~SistemaSolar();
  void Inicializa();
  void Executar();
};

#endif
