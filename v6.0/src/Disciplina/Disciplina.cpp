#include "../../include/Disciplina/Disciplina.h"
#include "../../include/Departamento/Departamento.h"
Disciplina::Disciplina() { Inicializa(); }

Disciplina::~Disciplina() {
  if (pDptoAssociado != NULL) {
    pDptoAssociado->removaDisciplina(this);
  }
  pDptoAssociado = NULL;
}

void Disciplina::Inicializa(int idNa, char nomeNa[],
                            char area_do_conhecimentoNA[], Departamento *pDpto,
                            int AulasSemanais, double media) {

  setArea_do_conhecimento(area_do_conhecimentoNA);
  setId(idNa);
  setNome(nomeNa);
  setDpto(pDpto);
  setNumMaxAlunos(45);
  setAulasSemanais(AulasSemanais);
  setMedia(media);
}

void Disciplina::setId(int idNa) { id = idNa; }

int Disciplina::getId() { return id; }

void Disciplina::setNome(char nomeNa[]) {
  strcpy(nome, nomeNa);
  ObjLAlunos.setNome(nomeNa);
}

char *Disciplina::getNome() { return nome; }

void Disciplina::setDpto(Departamento *pDpto) {
  pDptoAssociado = pDpto;
  if (pDpto != NULL) {
    pDpto->incluaDisciplina(this);
  }
}

Departamento *Disciplina::getDepartamento() { return pDptoAssociado; }

void Disciplina::setArea_do_conhecimento(char area_do_conhecimentoNA[]) {
  strcpy(area_do_conhecimento, area_do_conhecimentoNA);
}

char *Disciplina::getArea_do_conhecimento() { return area_do_conhecimento; }

void Disciplina::setNumMaxAlunos(int max) { ObjLAlunos.setNumMaxAlunos(max); }

int Disciplina::getNumMaxAlunos() { return ObjLAlunos.getNumMaxAlunos(); }

void Disciplina::listeAlunos() {
  cout << "Alunos da disciplina " << nome << endl;
  ObjLAlunos.listeAlunos();
}

void Disciplina::setMedia(double mediaNa) { media = mediaNa; }

double Disciplina::getMedia() { return media; }

void Disciplina::setAulasSemanais(int AulasSemanaisNa) {
  AulasSemanais = AulasSemanaisNa;
}

int Disciplina::getAulasSemanais() { return AulasSemanais; }

void Disciplina::incluaAluno(Aluno *aluno) {
  ObjLAlunos.incluaAluno(aluno);
}

void Disciplina::removaAluno(Aluno *aluno) {
  ObjLAlunos.removaAluno(aluno);
}
