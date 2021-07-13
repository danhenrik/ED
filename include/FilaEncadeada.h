#ifndef FILA_ENCADEADA
#define FILA_ENCADEADA

#include "Fila.h"
#include "Celula.h"

class FilaEncadeada : public Fila
{
public:
  // Cria uma fila vazia com uma única célula (cabeça).
  FilaEncadeada();
  /* Exclui completamente a lista da memória, excluindo 
  todas as células inclusive a cabeça.  */
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