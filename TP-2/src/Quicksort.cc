#include "Quicksort.h"

void Particao(int Esq, int Dir, int *i, int *j, Consciencia *A)
{
  Consciencia pivo, aux;
  *i = Esq;
  *j = Dir;
  pivo = A[(Esq + Dir) / 2];
  do
  {
    while (pivo.GetNome() > A[*i].GetNome())
      (*i)++;
    while (pivo.GetNome() < A[*j].GetNome())
      (*j)--;
    if (*i <= *j)
    {
      aux = A[*i];
      A[*i] = A[*j];
      A[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Consciencia *A)
{
  int i, j;
  Particao(Esq, Dir, &i, &j, A);

  if (Esq < j)
    Ordena(Esq, j, A);
  if (i < Dir)
    Ordena(i, Dir, A);
}

void QuickSort(Consciencia *A, int n)
{
  Ordena(0, n - 1, A);
}
