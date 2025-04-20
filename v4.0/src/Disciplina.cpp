#include "../include/Disciplina.h"
#include "../include/Aluno.h"

Disciplina::Disciplina() { Inicializa(); }

Disciplina::~Disciplina() {
  if (pDptoAssociado != NULL) {
    pDptoAssociado->removaDisciplina(this);
  }
}

void Disciplina::Inicializa(int idNa, char nomeNa[],
                            char area_do_conhecimentoNA[], Departamento *pDpto,
                            int NumMaxAlunos) {
  setArea_do_conhecimento(area_do_conhecimentoNA);
  setId(idNa);
  setNome(nomeNa);
  setDepartamento(pDpto);
  pProx = NULL;
  pAnt = NULL;
  pAlunoPrim = NULL;
  pAlunoAtual = NULL;
  setNumAlunos(0);
  setNumMaxAlunos(45);
}

void Disciplina::setId(int idNa) { id = idNa; }

int Disciplina::getId() { return id; }

void Disciplina::setNome(char nomeNa[]) { strcpy(nome, nomeNa); }

char *Disciplina::getNome() { return nome; }

void Disciplina::setDepartamento(Departamento *pDpto) {
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

void Disciplina::setProx(Disciplina *prox) { pProx = prox; }
void Disciplina::setAnt(Disciplina *ant) { pAnt = ant; }
Disciplina *Disciplina::getProx() { return pProx; }
Disciplina *Disciplina::getAnt() { return pAnt; }
void Disciplina::setNumMaxAlunos(int max) { NumMaxAlunos = max; }
int Disciplina::getNumMaxAlunos() { return NumMaxAlunos; }
void Disciplina::setNumAlunos(int num) { NumAlunos = num; }
int Disciplina::getNumAlunos() { return NumAlunos; }
void Disciplina::incluaAluno(Aluno *aluno) {
  if (aluno == NULL) {
    cout << "Erro: aluno nulo!" << endl;
    return;
  } else if (NumAlunos >= NumMaxAlunos) {
    cout << "Erro: numero maximo de alunos atingido!" << endl;
    return;
  } else {
    if (pAlunoPrim == NULL) {
      pAlunoPrim = aluno;
      pAlunoAtual = aluno;
      pAlunoAtual->setProx(NULL);
      pAlunoAtual->setAnt(NULL);
    } else {
      pAlunoAtual->setProx(aluno);
      aluno->setAnt(pAlunoAtual);
      pAlunoAtual = aluno;
      pAlunoAtual->setProx(NULL);
    }
  }
  NumAlunos++;
}
void Disciplina::removaAluno(Aluno *aluno) {

  if (aluno == NULL) {
    cout << "Erro: aluno nulo!" << endl;
    return;
  } else if (pAlunoPrim == NULL) {
    cout << "Erro: lista de alunos vazia!" << endl;
    return;
  } else {

    Aluno *paux = NULL;
    paux = pAlunoPrim;
    while (paux != NULL && paux != aluno) {
      paux = paux->getProx();
    }
    if (paux == NULL) {
      cout << "Erro: aluno nao encontrado!" << endl;
      return;
    } else if (paux == pAlunoPrim) {
      pAlunoPrim = paux->getProx();
      if (pAlunoPrim != NULL) {
        pAlunoPrim->setAnt(NULL);
      }
    } else if (paux == pAlunoAtual) {
      pAlunoAtual = paux->getAnt();
      if (pAlunoAtual != NULL) {
        pAlunoAtual->setProx(NULL);
      }
    } else {
      paux->getAnt()->setProx(paux->getProx());
      paux->getProx()->setAnt(paux->getAnt());
    }
    NumAlunos--;
  }
}
void Disciplina::listeAlunos() {
  Aluno *paux = NULL;
  paux = pAlunoPrim;
  while (paux != NULL) {
    cout << "O aluno " << paux->getNome() << " pertence a disciplina "
         << getNome() << endl;
    paux = paux->getProx();
  }
}
