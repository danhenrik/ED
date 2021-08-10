#include "Consciencia.h"

// Cria as duas arrays auxiliares valuesL e valuesR as junta ordenando
void Particao(Consciencia *A, int Esq, int Mid, int Dir);

// Ponto central do algoritmo de onde são feitas as partições, e no fim é 
// chamado a Particao que junta as partições devidamente ordenadas.
void Merge(Consciencia *A, int Esq, int Dir);

// Inicializador do algoritmo, necessário devido a escolha de implementação recursiva.
void MergeSort(Consciencia *A, int len);