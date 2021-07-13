#ifndef CELULA
#define CELULA

#include "Item.h"

class Celula
{
public:
  Celula();

private:
  Item item;
  Celula *prox;

  friend class FilaEncadeada;
};

#endif