#include "Consciencia.h"

// Constrói a heap
void Constroi(Consciencia *A, int len);

// Refaz (reorganiza) a heap, é nessa função que a ordenação acontece. 
void Refaz(int Esq, int Dir, Consciencia *A);

// Inicializador do algoritmo, chama a construção e depois vai reordenando todo o vetor.
void HeapSort(Consciencia *A, int len);
