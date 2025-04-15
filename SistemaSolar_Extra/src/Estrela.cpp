#include "../include/Estrela.h"
#include "../include/Planeta.h"

Estrela::Estrela(){
  Inicializa(0, NULL, 0);
}
Estrela::~Estrela(){

}
  void Estrela::Inicializa(int tmp_ex, Planeta*  pplaneta, int Na){
  cout << " I am shining " << endl;
  setTempoExistencia(tmp_ex);
  setNA(Na);
}
  void Estrela::setTempoExistencia(int tmp){
  tempo_existencia = tmp;
}

  int Estrela::getTempoExistencia(){
  return tempo_existencia;
}
