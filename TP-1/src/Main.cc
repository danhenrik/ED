#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "FilaEncadeada.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        throw "Please insert the test text file.";
    }
    string filename = argv[1];

    fstream file;
    file.open(filename, ios::in); // Read
    if (!file.is_open())
    {
        throw "Couldn't find file";
    }

    int bufferSize;
    file >> bufferSize;
    FilaEncadeada buffer[bufferSize];
    FilaEncadeada Hist;

    string input;
    while (getline(file, input))
    {
        stringstream ss(input);
        string command;
        ss >> command;
        if (command == "SEND")
        {
            for (int i = 0; i < bufferSize; i++)
            {
                if (!buffer[i].Vazia())
                {
                    Hist.Enfileira(buffer[i].Desenfileira());
                }
            }
        }
        else if (command == "FLUSH")
        {
            while (!Hist.Vazia())
            {
                Hist.Desenfileira().Imprime();
            }
            for (int i = 0; i < bufferSize; i++)
            {
                while (!buffer[i].Vazia())
                {
                    buffer[i].Desenfileira().Imprime();
                }
            }
        }
        else
        {
            int bufferIndex;
            ss >> bufferIndex;
            if (command == "INFO")
            {
                string name;
                ss >> name;
                string binarie;
                ss >> binarie;
                string data = name + " " + binarie;
                data.erase(0, 1);
                data.pop_back();
                buffer[bufferIndex].Enfileira(data);
            }
            else if (command == "WARN")
            {
                int index;
                ss >> index;
                buffer[bufferIndex].FuraFila(index);
            }
            else if (command == "TRAN")
            {
                int toIndex;
                ss >> toIndex;
                while (!buffer[bufferIndex].Vazia())
                {
                    buffer[toIndex].Enfileira(buffer[bufferIndex].Desenfileira());
                }
            }
            else if (command == "ERRO")
            {
                cout << "ERRO " << bufferIndex << endl;
                while (!buffer[bufferIndex].Vazia())
                {
                    buffer[bufferIndex].Desenfileira().Imprime();
                }
            }
        }
    }
    file.close();
    return 0;
}
