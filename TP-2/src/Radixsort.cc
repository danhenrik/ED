#include "Radixsort.h"

void sort(Consciencia *A, int Esq, int Dir, int bitIndx, int bitLen)
{
  Consciencia aux;
  int i = Esq, j = Dir;
  if (Dir <= Esq || bitIndx > bitLen - 1)
    return;
  while (j != i)
  {
    while (A[i].GetDado()[bitIndx] == '0' && (i < j))
      i++;
    while (A[j].GetDado()[bitIndx] == '1' && (j > i))
      j--;
    aux = A[i];
    A[i] = A[j];
    A[j] = aux;
  }
  if (A[Dir].GetDado()[bitIndx] == '0')
    j++;
  sort(A, Esq, j - 1, bitIndx + 1, bitLen);
  sort(A, j, Dir, bitIndx + 1, bitLen);
}

void RadixSort(Consciencia *A, int len, int bitLen)
{
  sort(A, 0, len - 1, 0, bitLen);
}
