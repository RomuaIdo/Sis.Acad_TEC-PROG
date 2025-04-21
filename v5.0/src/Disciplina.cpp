#include "../include/Disciplina.h"
#include "../include/Aluno.h"

Disciplina::Disciplina() { Inicializa(); }

Disciplina::~Disciplina() {
  if (pDptoAssociado != NULL) {
    pDptoAssociado->removaDisciplina(this);
  }
  pDptoAssociado = NULL;

  if (pElAlunoPrim != NULL) {
    ElAluno *paux = NULL;
    paux = pElAlunoPrim;
    while (paux != NULL) {
      ElAluno *paux2 = NULL;
      paux2 = paux->getProx();
      delete paux;
      paux = paux2;
    }
  }
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
  pProx = NULL;
  pAnt = NULL;
}

void Disciplina::Inicializa(int idNa, char nomeNa[],
                            char area_do_conhecimentoNA[], Departamento *pDpto,
                            int NumMaxAlunos, int AulasSemanais, double media) {
  setArea_do_conhecimento(area_do_conhecimentoNA);
  setId(idNa);
  setNome(nomeNa);
  setDepartamento(pDpto);
  pProx = NULL;
  pAnt = NULL;
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
  setNumAlunos(0);
  setNumMaxAlunos(45);
  setAulasSemanais(AulasSemanais);
  setMedia(media);
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
    ElAluno *novo_aluno = NULL;
    novo_aluno = new ElAluno();
    novo_aluno->setAluno(aluno);
    if (pElAlunoPrim == NULL) {
      pElAlunoPrim = novo_aluno;
      pElAlunoAtual = novo_aluno;
    } else {
      pElAlunoAtual->setProx(novo_aluno);
      novo_aluno->setAnt(pElAlunoAtual);
      pElAlunoAtual = novo_aluno;
    }
  }
  insertionsort();
  NumAlunos++;
}
void Disciplina::removaAluno(Aluno *aluno) {
  if (aluno == NULL) {
    cout << "Erro: aluno nulo!" << endl;
    return;
  } else if (pElAlunoPrim == NULL) {
    cout << "Erro: lista de alunos vazia!" << endl;
    return;
  } else {
    ElAluno *paux = NULL;
    paux = pElAlunoPrim;
    while (paux != NULL && paux->getAluno() != aluno) {
      paux = paux->getProx();
    }
    if (paux == NULL) {
      cout << "Erro: aluno nao encontrado!" << endl;
      return;
    } else if (paux == pElAlunoPrim) {
      pElAlunoPrim = paux->getProx();
      if (pElAlunoPrim != NULL) {
        pElAlunoPrim->setAnt(NULL);
      }
    } else if (paux == pElAlunoAtual) {
      pElAlunoAtual = paux->getAnt();
      if (pElAlunoAtual != NULL) {
        pElAlunoAtual->setProx(NULL);
      }
    } else {
      paux->getAnt()->setProx(paux->getProx());
      paux->getProx()->setAnt(paux->getAnt());
    }
    delete paux;
    NumAlunos--;
  }
}
void Disciplina::listeAlunos() {
  ElAluno *paux = NULL;
  paux = pElAlunoPrim;
  while (paux != NULL) {
    cout << "O aluno " << paux->getAluno()->getNome() << " esta na disciplina "
         << getNome() << endl;
    paux = paux->getProx();
  }
}

void Disciplina::setMedia(double mediaNa) { media = mediaNa; }

double Disciplina::getMedia() { return media; }

void Disciplina::insertionsort() {
  if (pElAlunoPrim == NULL || pElAlunoPrim->getProx() == NULL) {
    return;
  }

  ElAluno *paux = pElAlunoPrim->getProx();
  ElAluno *pauxant = pElAlunoPrim;
  while (paux != NULL) {
    if (strcmp(paux->getAluno()->getNome(), pauxant->getAluno()->getNome()) <
        0) {
      ElAluno *key = paux;
      ElAluno *paux2 = pauxant->getAnt();
      paux = paux->getProx();
      pauxant->setProx(paux);
      if (paux != NULL) {
        paux->setAnt(pauxant);
      }
      while (paux2 != NULL && strcmp(key->getAluno()->getNome(),
                                     paux2->getAluno()->getNome()) < 0) {
        paux2 = paux2->getAnt();
      }
      if (paux2 == NULL) {
        key->setProx(pElAlunoPrim);
        pElAlunoPrim->setAnt(key);
        key->setAnt(NULL);
        pElAlunoPrim = key;
      } else {
        paux2->getProx()->setAnt(key);
        key->setProx(paux2->getProx());
        key->setAnt(paux2);
        paux2->setProx(key);
      }
    }
    if (paux != NULL) {
      paux = paux->getProx();
      pauxant = pauxant->getProx();
    }
  }
  pElAlunoAtual = pauxant;
}

void Disciplina::setAulasSemanais(int AulasSemanaisNa) {
  AulasSemanais = AulasSemanaisNa;
}

int Disciplina::getAulasSemanais() { return AulasSemanais; }
