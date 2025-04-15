#ifndef _MAIN_H_ 
#define _MAIN_H_
#include "SistemaSolar.h"
class Main{
private:
  SistemaSolar sistemasolar;
public:
  Main();
  ~Main();
  void Inicializa();
  void Executa();
};
#endif
