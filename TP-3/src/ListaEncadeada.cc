#include <cmath>
#include "ListaEncadeada.h"

ListaEncadeada::ListaEncadeada() : Lista()
{
  primeiro = new Celula();
  ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada()
{
  Limpa();
  delete primeiro;
}

Item ListaEncadeada::GetItem(int pos)
{
  Celula *p;
  p = Posiciona(pos, false);
  return p->item;
}

void ListaEncadeada::SetItem(Item item, int pos)
{
  Celula *p;
  p = Posiciona(pos, false);
  p->item = item;
}

void ListaEncadeada::InsereInicio(Item item)
{
  Celula *nova;
  nova = new Celula();
  nova->item = item;
  nova->prox = primeiro->prox;
  primeiro->prox = nova;
  tam++;
  if (nova->prox == NULL)
    ultimo = nova;
};

void ListaEncadeada::InsereFinal(Item item)
{
  Celula *nova;
  nova = new Celula();
  nova->item = item;
  ultimo->prox = nova;
  ultimo = nova;
  tam++;
};

void ListaEncadeada::InserePosicao(Item item, int pos)
{
  Celula *p, *nova;
  p = Posiciona(pos, true); // posiciona na célula anterior
  nova = new Celula();
  nova->item = item;
  nova->prox = p->prox;
  p->prox = nova;
  tam++;
  if (nova->prox == NULL)
    ultimo = nova;
};

Item ListaEncadeada::RemoveInicio()
{
  ;
  Item aux;
  Celula *p;
  if (tam == 0)
    throw "ERRO: Lista vazia!";
  p = primeiro->prox;
  primeiro->prox = p->prox;
  tam--;
  if (primeiro->prox == NULL)
    ultimo = primeiro;
  aux = p->item;
  delete p;
  return aux;
}

Item ListaEncadeada::RemoveFinal()
{
  Item aux;
  Celula *p;
  if (tam == 0)
    throw "ERRO: Lista vazia!";
  // posiciona p na celula anterior à última
  p = Posiciona(tam, true);
  p->prox = NULL;
  tam--;
  aux = ultimo->item;
  delete ultimo;
  ultimo = p;
  return aux;
}

Item ListaEncadeada::RemovePos(int pos)
{
  ;
  Item aux;
  Celula *p, *q;
  if (tam == 0)
    throw "ERRO: Lista vazia!";
  // posiciona p na celula anterior à pos
  p = Posiciona(pos, true);
  q = p->prox;
  p->prox = q->prox;
  tam--;
  aux = q->item;
  delete q;
  if (p->prox == NULL)
    ultimo = p;
  return aux;
}

Item ListaEncadeada::Pesquisa(string key)
{
  Item aux;
  Celula *p;
  if (tam == 0)
    throw "ERRO: Lista vazia!";
  p = primeiro->prox;
  while (p != NULL)
  {
    if (p->item.GetValue() == key)
    {
      aux = p->item;
      break;
    }
    p = p->prox;
  }
  return aux;
};

void ListaEncadeada::Imprime()
{
  Celula *p;
  p = primeiro->prox;
  while (p != NULL)
  {
    p->item.Imprime();
    p = p->prox;
  }
  cout << "\n";
};

void ListaEncadeada::ImprimeSomaBinaria()
{
  Celula *p;
  int sum = 0;
  p = primeiro->prox;
  while (p != NULL)
  {
    int bitSum = 0;
    string binarie = p->item.GetValue();
    int exp = 0;
    for (int i = binarie.length() - 1; i >= 0; i--)
    {
      if (binarie[i] == '1')
      {
        bitSum += pow(2, exp);
      }
      exp++;
    }
    sum += bitSum;
    p = p->prox;
  }
  cout << sum << endl;
}

void ListaEncadeada::Limpa()
{
  Celula *p;
  p = primeiro->prox;
  while (p != NULL)
  {
    primeiro->prox = p->prox;
    delete p;
    p = primeiro->prox;
  }
  ultimo = primeiro;
  tam = 0;
};

Celula *ListaEncadeada::Posiciona(int pos, bool antes)
{
  Celula *p;
  int i;
  if ((pos > tam) || (pos <= 0))
    throw "ERRO: Posicao Invalida!";
  // Posiciona na célula anterior a desejada
  p = primeiro;
  for (i = 1; i < pos; i++)
  {
    p = p->prox;
  }
  // vai para a próxima
  // se antes for false
  if (!antes)
    p = p->prox;
  return p;
}
