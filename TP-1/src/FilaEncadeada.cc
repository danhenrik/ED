#include "FilaEncadeada.h"

FilaEncadeada::FilaEncadeada() : Fila()
{
  front = new Celula;
  back = front;
}

FilaEncadeada::~FilaEncadeada()
{
  Clear();
  delete front;
}

void FilaEncadeada::Enfileira(Item item)
{
  Celula *nova;
  nova = new Celula();
  nova->item = item;
  back->prox = nova;
  back = nova;
  tam++;
}

Item FilaEncadeada::Desenfileira()
{
  Celula *cel;
  Item aux;

  if (this->Vazia())
  {
    throw "Fila vazia.";
  }

  aux = front->prox->item;
  cel = front;
  front = front->prox;
  delete cel;
  tam--;
  return aux;
}

void FilaEncadeada::Clear()
{
  Celula *cel;

  cel = front->prox;
  while (cel != NULL)
  {
    front->prox = cel->prox;
    delete cel;
    cel = front->prox;
  }
  back = front;
  tam = 0;
}

void FilaEncadeada::FuraFila(int pos)
{
  Celula *cel, *aux;
  cel = front;
  for (int i = 0; i < pos; i++)
  {
    cel = cel->prox;
  }
  aux = cel->prox;
  cel->prox = aux->prox;
  aux->prox = front->prox;
  front->prox = aux;
}