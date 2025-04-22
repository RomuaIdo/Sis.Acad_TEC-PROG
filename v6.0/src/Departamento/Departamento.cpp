#include "../../include/Departamento/Departamento.h"
#include "../../include/Disciplina/Disciplina.h"
#include <string.h>

Departamento::Departamento() { Inicializa(); }

Departamento::~Departamento() {
  if (pUniv != NULL) {
    pUniv = NULL;
  }
  if (ObjLDisciplinas != NULL) {
    delete ObjLDisciplinas;
    ObjLDisciplinas = NULL;
  }
}

void Departamento::Inicializa(char *nomeNa, Universidade *puni, int idNa) {
  setId(idNa);
  ObjLDisciplinas = new ListaDisciplinas();
  setNome(nomeNa);
  setUniversidade(puni);

}

void Departamento::setNome(char *nomeNa) {
  strcpy(nomeD, nomeNa);
  ObjLDisciplinas->setNome(nomeNa);
}


char *Departamento::getNome() { return nomeD; }

void Departamento::setUniversidade(Universidade *puni) { pUniv = puni; }

Universidade *Departamento::getUniversidade() { return pUniv; }

void Departamento::incluaDisciplina(Disciplina *pDisciplina) {
  ObjLDisciplinas->incluaDisciplina(pDisciplina);
}

void Departamento::listeDisciplinas() {
  cout << "Disciplinas do departamento " << nomeD << endl;
  ObjLDisciplinas->listeDisciplinas();
}

void Departamento::removaDisciplina(Disciplina *pDisciplina) {
  ObjLDisciplinas->removaDisciplina(pDisciplina);
}
void Departamento::setId(int idNa) { id = idNa; }
int Departamento::getId() { return id; }
