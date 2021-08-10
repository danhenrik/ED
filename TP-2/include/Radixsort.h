#include "Consciencia.h"

// Radixsort implementado a partir do ponto de dado já como bit (não necessitando a conversão)
// onde de forma recursiva se itera sobre os caracteres do bit e os troca e particiona de acordo.
void sort(Consciencia *A, int l, int r, int bitIndx, int bitLen);

// Inicializador necessário devido a escolha de implementação recursiva.
void RadixSort(Consciencia *A, int len, int bitLen);