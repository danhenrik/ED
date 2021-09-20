#include "Item.h"
#include "ListaEncadeada.h"

class Node
{
public:
  /* Cria um nó vazio que não aponta pra ninguem. */
  Node();

private:
  Item nome;
  ListaEncadeada binaries;
  Node *esq;
  Node *dir;
  /* Possibilita que pela classe ArvoreBinaria o item,
  os binparios e as referencias seja atribuidos todos
  ao nó sem a necessidade da criação de métodos específicos
  para cada coisinha. */
  friend class ArvoreBinaria;
};