#include "../include/Pessoa.h"



Pessoa::Pessoa(){
  Inicializa();
}
Pessoa::~Pessoa(){
}

void Pessoa::Inicializa(int diaNa, int mesNa, int anoNa, char* nomeNa){
    dia = diaNa;
    mes = mesNa;
    ano = anoNa;
    idade = 0;
    strcpy(nomeP, nomeNa);
    setUnivAfiliado(0);
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
    cout << "Idade de " << nomeP << ": " << idade << endl;
}

void Pessoa::OndeTrabalho(){
    cout << nomeP << " trabalha para a " << pUnivAfiliado->getNome() << endl;
}

void Pessoa::setUnivAfiliado(Universidade* pUniv){
    pUnivAfiliado = pUniv;
}
