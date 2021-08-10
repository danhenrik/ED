#include "Mergesort.h"

void Particao(Consciencia *A, int Esq, int Mid, int Dir)
{
  int EsqArrSize = Mid - Esq + 1;
  int DirArrSize = Dir - Mid;

  // Cria as arrays auxiliares
  Consciencia *valuesL = new Consciencia[EsqArrSize];
  Consciencia *valuesR = new Consciencia[DirArrSize];

  // Divide os dados entre as duas arrays
  for (int i = 0; i < EsqArrSize; i++)
    valuesL[i] = A[Esq + i];
  for (int j = 0; j < DirArrSize; j++)
    valuesR[j] = A[Mid + 1 + j];

  int indexValuesL = 0;
  int indexValuesR = 0;
  int indexA = Esq;

  // Junta as duas arrays de volta a array principal de acordo com os valores dos nomes.
  while (indexValuesL < EsqArrSize && indexValuesR < DirArrSize)
  {
    if (valuesL[indexValuesL].GetNome() <= valuesR[indexValuesR].GetNome())
    {
      A[indexA] = valuesL[indexValuesL];
      indexValuesL++;
    }
    else
    {
      A[indexA] = valuesR[indexValuesR];
      indexValuesR++;
    }
    indexA++;
  }
  while (indexValuesL < EsqArrSize)
  {
    A[indexA] = valuesL[indexValuesL];
    indexValuesL++;
    indexA++;
  }
  while (indexValuesR < DirArrSize)
  {
    A[indexA] = valuesR[indexValuesR];
    indexValuesR++;
    indexA++;
  }
}

void Merge(Consciencia *A, int Esq, int Dir)
{
  if (Esq >= Dir)
    return; // Condição de parada da recursão
  int Mid = Esq + (Dir - Esq) / 2;
  Merge(A, Esq, Mid);
  Merge(A, Mid + 1, Dir);
  Particao(A, Esq, Mid, Dir);
}

void MergeSort(Consciencia *A, int len)
{
  Merge(A, 0, len - 1);
}