#ifndef FILA_ENCADEADA
#define FILA_ENCADEADA

#include "Fila.h"
#include "Celula.h"

class FilaEncadeada : public Fila
{
public:
  FilaEncadeada();
  virtual ~FilaEncadeada();

  virtual void Enfileira(Item);
  virtual Item Desenfileira();
  virtual void Clear();
  virtual void FuraFila(int);

private:
  Celula *front;
  Celula *back;
};

#endif