#include "../include/Pessoa.h"



Pessoa::Pessoa(int diaNa, int mesNa, int anoNa){
    dia = diaNa;
    mes = mesNa;
    ano = anoNa;
    idade = 0;
}

void Pessoa::CalculaIdade(int diaAtual, int mesAtual, int anoAtual){
    idade = anoAtual - ano;
    if(mesAtual < mes || (mesAtual == mes && diaAtual < dia)){
      idade--;
    }
}
int Pessoa::getIdade(){
    return idade;
}
void Pessoa::printIdade(){
    printf("Idade: %d\n", idade);
}
