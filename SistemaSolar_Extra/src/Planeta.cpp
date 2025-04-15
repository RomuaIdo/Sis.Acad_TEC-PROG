#include "../include/Planeta.h"


Planeta::Planeta() : Astro() {
  Inicializa(0, NULL, 0); 
}

Planeta::~Planeta(){
}

void Planeta::Inicializa(int tmp_orb, Estrela* ps, int na){
  setSol(ps);
  setNA(na);
  setTempoOrbita(tmp_orb);
}
  void Planeta::setTempoOrbita(int tmp){
  tempo_orbita = tmp;
}
  void Planeta::setSol(Estrela* pS){
  pSol = pS;
}

  float Planeta::CalculaQuantOrbita(){
  float resultado = 0.0;
  if(pSol != NULL){
    int tempo_sol = pSol->getTempoExistencia();
    resultado = (float)tempo_sol/tempo_orbita;
  }
  else{
    cout << "Ponteiro do Sol esta nulo " << endl;
    resultado = -1.0;
  }
  return resultado;
}
