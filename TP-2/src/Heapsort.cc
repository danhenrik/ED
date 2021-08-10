#include "Heapsort.h"

void Constroi(Consciencia *A, int len)
{
  int Esq = (len / 2);
  while (Esq > 0)
  {
    Esq--;
    Refaz(Esq, len, A);
  }
}

void Refaz(int Esq, int Dir, Consciencia *A)
{
  int i = Esq, j;
  Consciencia x;
  j = 2 * i + 1;
  x = A[i];
  while (j < Dir)
  {
    if (A[j].GetDado() < A[j + 1].GetDado())
      j++;
    if (x.GetDado() >= A[j].GetDado())
      break;
    A[i] = A[j];
    i = j;
    j = i * 2;
  }
  A[i] = x;
}

void HeapSort(Consciencia *A, int len)
{
  Consciencia aux;
  Constroi(A, len); 
  int Esq = 0, Dir = len - 1;
  while (Dir != Esq)
  { 
    aux = A[Esq];
    A[Esq] = A[Dir];
    A[Dir] = aux;
    Dir--;
    Refaz(Esq, Dir, A);
  }
}