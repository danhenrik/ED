#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std::chrono;

#include "Consciencia.h"
#include "Quicksort.h"
#include "Heapsort.h"
#include "Mergesort.h"
#include "Radixsort.h"

// Função implementada para medir os tempos e fazer os gráficos demandados.
void test(string filename)
{
    int linesOpt[5] = {1000, 10000, 50000, 100000, 200000};
    int configOpt[4] = {1, 2, 3, 4};
    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open())
    {
        throw "Couldn't find file";
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            int bitLength, ALen = linesOpt[i];
            Consciencia *A = new Consciencia[ALen];
            string input;
            for (int i = 0; i < ALen; i++)
            {
                getline(file, input);
                stringstream ss(input);
                string nome, dado;
                ss >> nome;
                ss >> dado;
                bitLength = dado.length();
                A[i] = Consciencia(nome, dado);
            }
            file.close();
            int config = configOpt[j];

            auto start = high_resolution_clock::now();
            if (config == 1)
            {
                HeapSort(A, ALen);
                QuickSort(A, ALen);
            }
            else if (config == 2)
            {
                RadixSort(A, ALen, bitLength);
                QuickSort(A, ALen);
            }
            else if (config == 3)
            {
                HeapSort(A, ALen);
                MergeSort(A, ALen);
            }
            else if (config == 4)
            {
                RadixSort(A, ALen, bitLength);
                MergeSort(A, ALen);
            }
            auto stop = high_resolution_clock::now();
            auto time = duration_cast<microseconds>(stop - start);
            cout << "Config " << configOpt[j] << " " << linesOpt[i] << " lines: " << time.count() << " ms" << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        throw "Please insert the parameters in the following order: dataInputFile.txt configuration linesQtd";
    }

    string filename = argv[1];
    stringstream conveter;
    int config, linesQtd;
    conveter << argv[2];
    conveter >> config;
    conveter.clear();
    conveter << argv[3];
    conveter >> linesQtd;

    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open())
    {
        throw "Couldn't find file";
    }

    int bitLength, ALen = linesQtd;
    Consciencia *A = new Consciencia[ALen];
    string input;
    for (int i = 0; i < ALen; i++)
    {
        if(file.eof()){
            ALen = i;
            break;
        }
        getline(file, input);
        stringstream ss(input);
        string nome, dado;
        ss >> nome;
        ss >> dado;
        bitLength = dado.length();
        A[i] = Consciencia(nome, dado);
    }
    file.close();

    if (config == 1)
    {
        HeapSort(A, ALen);
        QuickSort(A, ALen);
    }
    else if (config == 2)
    {
        RadixSort(A, ALen, bitLength);
        QuickSort(A, ALen);
    }
    else if (config == 3)
    {
        HeapSort(A, ALen);
        MergeSort(A, ALen);
    }
    else if (config == 4)
    {
        RadixSort(A, ALen, bitLength);
        MergeSort(A, ALen);
    }

    for (int i = 0; i < ALen; i++)
    {
        A[i].Imprime();
    }

    // test(filename); // Chamada da função de teste que mostra os resultados para diversos métodos
    return 0;
}
