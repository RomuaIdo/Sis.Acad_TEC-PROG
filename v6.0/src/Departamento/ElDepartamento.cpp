#include "../../include/Departamento/ElDepartamento.h"



ElDepartamento::ElDepartamento(){
  departamento = NULL;
  pProx = NULL;
  pAnt = NULL;
}

ElDepartamento::~ElDepartamento(){
  departamento = NULL;
  pProx = NULL;
  pAnt = NULL;
}

void ElDepartamento::Inicializa(Departamento* departamentoNa){
  departamento = departamentoNa;
  pProx = NULL;
  pAnt = NULL;
}

Departamento* ElDepartamento::getDepartamento(){
  return departamento;
}

ElDepartamento* ElDepartamento::getProx(){
  return pProx;
}

ElDepartamento* ElDepartamento::getAnt(){
  return pAnt;
}

void ElDepartamento::setProx(ElDepartamento* pProxNa){
  pProx = pProxNa;
}

void ElDepartamento::setAnt(ElDepartamento* pAntNa){
  pAnt = pAntNa;
}

void ElDepartamento::setDepartamento(Departamento* departamentoNa){
  departamento = departamentoNa;
}

