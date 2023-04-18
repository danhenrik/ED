#include <iostream>

void ParticaoM(int *A, int Esq, int Mid, int Dir)
{
  int EsqArrSize = Mid - Esq + 1;
  int DirArrSize = Dir - Mid;

  // Cria as arrays auxiliares
  int *valuesL = new int[EsqArrSize];
  int *valuesR = new int[DirArrSize];

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
    if (valuesL[indexValuesL] <= valuesR[indexValuesR])
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

void Merge(int *A, int Esq, int Dir)
{
  if (Esq >= Dir)
    return; // Condição de parada da recursão
  int Mid = Esq + (Dir - Esq) / 2;
  Merge(A, Esq, Mid);
  Merge(A, Mid + 1, Dir);
  ParticaoM(A, Esq, Mid, Dir);
}

void MergeSort(int *A, int len)
{
  Merge(A, 0, len - 1);
}

// ---------------------------------------------------------------------------

void ParticaoQ(int Esq, int Dir, int *i, int *j, int *A)
{
  int pivo, aux;
  *i = Esq;
  *j = Dir;
  pivo = A[(Esq + Dir) / 2];
  do
  {
    while (pivo > A[*i])
      (*i)++;
    while (pivo < A[*j])
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

void Ordena(int Esq, int Dir, int *A)
{
  int i, j;
  ParticaoQ(Esq, Dir, &i, &j, A);

  if (Esq < j)
    Ordena(Esq, j, A);
  if (i < Dir)
    Ordena(i, Dir, A);
}

void QuickSort(int *A, int n)
{
  Ordena(0, n - 1, A);
}

// -------------------------------------------------------------------------

void Refaz(int Esq, int Dir, int *A)
{
  int i = Esq, j;
  int x;
  j = 2 * i + 1;
  x = A[i];
  while (j < Dir)
  {
    if (A[j] < A[j + 1])
      j++;
    if (x >= A[j])
      break;
    A[i] = A[j];
    i = j;
    j = i * 2;
  }
  A[i] = x;
}

void Constroi(int *A, int len)
{
  int Esq = (len / 2);
  while (Esq > 0)
  {
    Esq--;
    Refaz(Esq, len, A);
  }
}

void HeapSort(int *A, int len)
{
  int aux;
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

int main()
{
  // Q5
  // int array5[9] = {60, 40, 20, 70, 90, 50, 80, 30, 10};
  // QuickSort(array5, 9);

  // Q6
  // int array6[9] = {8, 10, 12, 6, 4, 18, 2, 14, 16};
  // HeapSort(array6, 9);

  // Q3
  // int array3[9] = {35, 5, 15, 25, 45, 40, 10, 20};
  // QuickSort(array3, 9);

  // Q12
  // int array12[9] = {50,30,80,10,60,40,70,20};
  // MergeSort(array12, 9);

  // Q2 minha
  // int array[9] = {16, 20, 24, 12, 8, 36, 4, 28, 32};
  // HeapSort(array, 9);

  // Q9 minha
  // int array[9] = {7, 4, 3, 6, 9, 8, 2, 1, 5};
  // int array[9] = {35, 5, 30, 15, 25, 45, 40, 10, 20};
  // QuickSort(array, 9);

  // Q10 minha
  int array[9] = {35, 21, 56, 7, 42, 28, 49, 14};
  MergeSort(array, 9);
  return 0;
}