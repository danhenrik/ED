#include "Consciencia.h"

// Ordena a partição recebida.
void Particao(int, int, int *, int *, Consciencia *);

// Gera as partições e as ordena por meio da chamada da func Particao. (Ponto central do algoritmo).
void Ordena(int, int, Consciencia *);

// Inicializador do algoritmo necessário devido a implementação recursiva.
void QuickSort(Consciencia *, int);
