#ifndef CONSCIENCIA
#define CONSCIENCIA

#include <iostream>
#include <string>

using namespace std;

class Consciencia
{
public:
  // Cria um item vazio.
  Consciencia();
  // Cria atribuindo a primeira string ao campo nome e a segunda ao campo dado.
  Consciencia(string nome, string binarie);
  // Atribui a string passada ao nome.
  void SetNome(string nome);
  // Atribui a string passada ao dado.
  void SetDado(string dado);
  // Retorna o nome.
  string GetNome();
  // Retorna o dado.
  string GetDado();
  // Imprime nome e dado no terminal.
  void Imprime();

private:
  string nome;
  string dado;
};

#endif