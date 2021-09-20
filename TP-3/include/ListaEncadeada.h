#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include "Lista.h"
#include "Celula.h"

class ListaEncadeada : public Lista
{
public:
  /* Inicializa a lista instanciando uma Celula e atribuindo ela a frente e tras (caracteriza uma lista vazia).*/
  ListaEncadeada();
  /* Deleta a lista primeiro limpando-a e por último excluindo seu primeiro e único elemento.*/
  ~ListaEncadeada();

  /* Retorna o item na posição passada na lista. */
  Item GetItem(int pos);
  /* Adiciona o item passado no parâmetro na posição passada da lista. */
  void SetItem(Item item, int pos);
  /* Adiciona o item passado como parâmetro no inicio da lista. */
  void InsereInicio(Item item);
  /* Adiciona o item passado como parâmetro no fim da lista. */
  void InsereFinal(Item item);
  /* Adiciona o item passado como parâmetro na posição passada. */
  void InserePosicao(Item item, int pos);
  /* Retira e retorna o primeiro item da lista. */
  Item RemoveInicio();
  /* Retira e retorna o último item da lista. */
  Item RemoveFinal();
  /* Retira e retorna o elemento na posição passada como parâmetro da lista. */
  Item RemovePos(int pos);
  /* Pesquisa um item com a chave igual a string passada. */
  Item Pesquisa(string key);
  /* Imprime todos os items da lista na ordem. */
  void Imprime();
  /* Imprime todos os items da lista convertidos em decimais na ordem. */
  void ImprimeSomaBinaria();
  /* Limpa a lista deixando apenas a célula cabeça. */
  void Limpa();

private:
  Celula *primeiro;
  Celula *ultimo;
  Celula *Posiciona(int pos, bool antes);
};

#endif