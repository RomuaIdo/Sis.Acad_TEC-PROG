#include "../../include/Aluno/LAlunos.h"
#include "../../include/Aluno/Aluno.h"

ListaAlunos::ListaAlunos() { Inicializa(); }

ListaAlunos::~ListaAlunos() {
  ElAluno *pElAlunoAux;
  while (pElAlunoPrim != NULL) {
    pElAlunoAux = pElAlunoPrim;
    pElAlunoPrim = pElAlunoPrim->getProx();
    delete pElAlunoAux;
  }
}

void ListaAlunos::setNome(char nomeNa[]) { strcpy(nome, nomeNa); }

char *ListaAlunos::getNome() { return nome; }

void ListaAlunos::Inicializa(int NumMaxAlunosNa, char nomeNa[]) {
  NumMaxAlunos = NumMaxAlunosNa;
  strcpy(nome, nomeNa);
  NumAlunos = 0;
  pElAlunoPrim = NULL;
  pElAlunoAtual = NULL;
}

void ListaAlunos::setNumMaxAlunos(int max) { NumMaxAlunos = max; }

int ListaAlunos::getNumMaxAlunos() { return NumMaxAlunos; }

int ListaAlunos::getNumAlunos() { return NumAlunos; }

void ListaAlunos::incluaAluno(Aluno *aluno) {
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
void ListaAlunos::removaAluno(Aluno *aluno) {
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
void ListaAlunos::listeAlunos() {
  ElAluno *paux = NULL;
  paux = pElAlunoPrim;
  while (paux != NULL) {
    cout << "O aluno " << paux->getAluno()->getNome() << " esta na disciplina "
         << nome << endl;
    paux = paux->getProx();
  }
}

void ListaAlunos::insertionsort() {
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
