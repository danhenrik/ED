#ifndef FILA
#define FILA

#include "Item.h"

class Fila
{
public:
  /* Inicializa uma instancia de fila setando 
  seu tamanho para 0.  */
  Fila() { tam = 0; };
  // Retorna o tamanho da fila.
  int GetTamanho() { return tam; };
  // Retorna se a lista está vazia.
  bool Vazia() { return tam == 0; };

  // Adiciona o Item passado como parâmetro no fim da fila.
  virtual void Enfileira(Item) = 0;
  // Retira e retorna o primeiro Item da fila.
  virtual Item Desenfileira() = 0;
  // Limpa a lista deixando apenas a célula cabeça
  virtual void Clear() = 0;
  /* Pega o Item na posição passada e o passa para o início
  da fila  */
  virtual void FuraFila(int) = 0;

protected:
  int tam;
};

#endif