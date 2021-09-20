#ifndef LISTA
#define LISTA

#include "Item.h"

class Lista
{
public:
  /* Inicializa uma instancia de lista setando 
  seu tamanho para 0.  */
  Lista() { tam = 0; };
  /* Retorna o tamanho da lista. */
  int GetTamanho() { return tam; };
  /* Retorna se a lista está vazia. */
  bool Vazia() { return tam == 0; };

  /* Retorna o item na posição passada na lista. */
  virtual Item GetItem(int pos) = 0;
  /* Adiciona o item passado no parâmetro na posição passada da lista. */
  virtual void SetItem(Item b, int pos) = 0;
  /* Adiciona o item passado como parâmetro no inicio da lista. */
  virtual void InsereInicio(Item b) = 0;
  /* Adiciona o item passado como parâmetro no fim da lista. */
  virtual void InsereFinal(Item b) = 0;
  /* Retira e retorna o primeiro item da lista. */
  virtual Item RemoveInicio() = 0;
  /* Retira e retorna o último item da lista. */
  virtual Item RemoveFinal() = 0;
  /* Retira e retorna o elemento na posição passada como parâmetro da lista. */
  virtual Item RemovePos(int pos) = 0;
  /* Pesquisa um item com a chave igual a string passada. */
  virtual Item Pesquisa(string key) = 0;
  /* Imprime todos os items da lista na ordem. */
  virtual void Imprime() = 0;
  /* Limpa a lista deixando apenas a célula cabeça. */
  virtual void Limpa() = 0;

protected:
  int tam;
};

#endif