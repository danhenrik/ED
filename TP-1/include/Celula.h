#ifndef CELULA
#define CELULA

#include "Item.h"

class Celula
{
public:
  // Cria uma célula isolada, não aponta pra ninguem
  Celula();

private:
  Item item;
  Celula *prox;

  /* Possibilita que pela classe FilaEncadeada o item 
  seja atribuido a célula sem a necessidade da criação 
  de um método para isso.   */
  friend class FilaEncadeada;
};

#endif