#ifndef FILA
#define FILA

#include "Item.h"

class Fila
{
public:
  Fila() { tam = 0; };
  int GetTamanho() { return tam; };
  bool Vazia() { return tam == 0; };

  virtual void Enfileira(Item) = 0;
  virtual Item Desenfileira() = 0;
  virtual void Clear() = 0;
  virtual void FuraFila(int) = 0;

protected:
  int tam;
};

#endif