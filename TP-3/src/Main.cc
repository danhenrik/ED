#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "ArvoreBinaria.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        throw "Please exec this program passing the datafile as a parameter.";
    }

    string filename = argv[1];

    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open())
    {
        throw "Couldn't find file";
    }

    int inputLines;
    file >> inputLines;
    string input;
    /* Por algum motivo esse 1º getline da uma saída vazia então se usa
    ela fora do loop uma vez pois caso isso aconteça dentro do loop isso
    causaria sérios problemas. */
    getline(file, input);
    ArvoreBinaria A;
    for (int i = 0; i <= inputLines - 1; i++)
    {
        getline(file, input);
        stringstream ss(input);
        string nome, dado;
        ss >> nome;
        ss >> dado;

        // Joga na árvore
        A.Insere(nome, dado);
    }
    /* Imprime os nomes no caminhamento central. */
    A.Caminha(2);
    /* Lê até o final do arquivo e printa os nós pedidos convertendo o 
    binaraio pra decimal e removendo-os da árvore */
    while (getline(file, input))
    {
        /* A entrada vem com uma quebra de linha então é preciso uma 
        stream para retirar isso e o search funcionar. */
        stringstream parser(input);
        string search;
        parser >> search;
        A.Pesquisa(search);
    }
    /* Imprime apenas os nomes do resto dos elementos da árvore (creio que 
    no caminhemento central) */
    A.Caminha(2);

    file.close();
    return 0;
}
