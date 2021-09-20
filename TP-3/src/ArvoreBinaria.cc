#include "ArvoreBinaria.h"

ArvoreBinaria::ArvoreBinaria()
{
  root = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
  Limpa();
}

void ArvoreBinaria::Insere(string nome, string dado)
{
  InsereRecursivo(root, nome, dado);
}

void ArvoreBinaria::Pesquisa(string nome)
{
  if (nome != "")
  {
    Node *aux = PesquisaRecursivo(root, nome);
    aux->nome.Imprime();
    aux->binaries.ImprimeSomaBinaria();
    Remove(nome);
  }
}

void ArvoreBinaria::Remove(string nome)
{
  RemoveRecursivo(root, nome);
}

void ArvoreBinaria::Caminha(int pos)
{
  switch (pos)
  {
  case 1:
    PreOrdem(root);
    break;
  case 2:
    InOrdem(root);
    break;
  case 3:
    PosOrdem(root);
    break;
  }
  cout << endl;
}

void ArvoreBinaria::Limpa()
{
  ApagaRecursivo(root);
  root = NULL;
}

void ArvoreBinaria::InsereRecursivo(Node *&p, string nome, string dado)
{
  if (p == NULL)
  {
    p = new Node();
    p->nome.SetValue(nome);
    Item aux;
    aux.SetValue(dado);
    p->binaries.InsereFinal(aux);
  }
  else if (p->nome.GetValue() == nome)
  {
    Item aux;
    aux.SetValue(dado);
    p->binaries.InsereFinal(aux);
  }
  else
  {
    if (nome < p->nome.GetValue())
      InsereRecursivo(p->esq, nome, dado);
    else
      InsereRecursivo(p->dir, nome, dado);
  }
}

Node *ArvoreBinaria::PesquisaRecursivo(Node *p, string nome)
{
  if (p == NULL)
  {
    return 0;
  }
  if (nome == p->nome.GetValue())
  {
    return p;
  }
  else if (nome < p->nome.GetValue())
    return PesquisaRecursivo(p->esq, nome);
  else
    return PesquisaRecursivo(p->dir, nome);
}

void ArvoreBinaria::RemoveRecursivo(Node *&p, string nome)
{
  Node *aux;
  if (p == NULL)
  {
    throw("Item nao está presente");
  }
  if (nome < p->nome.GetValue())
    return RemoveRecursivo(p->esq, nome);
  else if (nome > p->nome.GetValue())
    return RemoveRecursivo(p->dir, nome);
  else
  {
    if (p->dir == NULL)
    {
      aux = p;
      p = p->esq;
      free(aux);
    }
    else if (p->esq == NULL)
    {
      aux = p;
      p = p->dir;
      free(aux);
    }
    else
      Antecessor(p, p->esq);
  }
}

void ArvoreBinaria::Antecessor(Node *n, Node *&r)
{
  if (r->dir != NULL)
  {
    Antecessor(n, r->dir);
    return;
  }
  n->nome = r->nome;
  n->binaries = r->binaries;
  n = r;
  r = r->esq;
  free(n);
}

void ArvoreBinaria::ApagaRecursivo(Node *p)
{
  if (p != NULL)
  {
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
  }
}

void ArvoreBinaria::PreOrdem(Node *p)
{
  if (p != NULL)
  {
    p->nome.Imprime();
    PreOrdem(p->esq);
    PreOrdem(p->dir);
  }
}

void ArvoreBinaria::InOrdem(Node *p)
{
  if (p != NULL)
  {
    InOrdem(p->esq);
    p->nome.Imprime();
    InOrdem(p->dir);
  }
}

void ArvoreBinaria::PosOrdem(Node *p)
{
  if (p != NULL)
  {
    PosOrdem(p->esq);
    PosOrdem(p->dir);
    p->nome.Imprime();
  }
}