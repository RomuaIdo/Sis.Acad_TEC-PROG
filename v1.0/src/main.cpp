#include "../include/Pessoa.h"


int main(){
  Pessoa Einstein(14, 3, 1879);
  Pessoa Newton(25, 12, 1642);
  
  Einstein.CalculaIdade(9, 4, 2025);
  Newton.CalculaIdade(9, 4, 2025);
 
  Einstein.printIdade();
  Newton.printIdade();
  return 0;
}
