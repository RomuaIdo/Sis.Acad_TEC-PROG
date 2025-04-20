#include "Pessoa.h"


class Professor : public Pessoa {
private:
  Universidade* pUnivAfiliado;
  Departamento* pDptoAfiliado;

public:
  Professor();
  ~Professor();
  void Inicializa(int diaNa = 0, int mesNa = 0, int anoNa = 0, char* nomeNa = "",
                  Universidade* pUnivAfiliado = NULL,
                  Departamento* pDptoAfiliado = NULL);
  void setUnivAfiliado(Universidade* pUnivAfiliado = NULL);
  Universidade* getUnivAfiliado();
  void setDptoAfiliado(Departamento* pDptoAfiliado = NULL);
  Departamento* getDptoAfiliado();
  void OndeTrabalho();
  void QualDepartamentoTrabalho();
};
