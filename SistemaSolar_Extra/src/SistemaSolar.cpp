#include "../include/SistemaSolar.h"

SistemaSolar::SistemaSolar(){
  Inicializa();
}

SistemaSolar::~SistemaSolar(){
  cout << "tchau" << endl;
}
void SistemaSolar::Inicializa(){
  Jupiter.Inicializa(0, &Sol, 0);
  cout << "oi" << endl;
  Jupiter.setTempoOrbita(30);
  Sol.setTempoExistencia(30000);
  Jupiter.setSol(&Sol);
  Executar();
}

void SistemaSolar::Executar(){
  float q_orbita = 0.0;
  q_orbita = Jupiter.CalculaQuantOrbita();
  cout << "Quantidade de orbitas: " << q_orbita << endl;
  cout << "Numero Astronomico de Sol: " << Sol.getNA() << endl;
}
