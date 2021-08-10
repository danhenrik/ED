#include "Consciencia.h"

Consciencia::Consciencia(){};

Consciencia::Consciencia(std::string n, std::string d)
{
  nome = n;
  dado = d;
}

void Consciencia::SetNome(std::string n)
{
  nome = n;
}

void Consciencia::SetDado(std::string d)
{
  dado = d;
}

std::string Consciencia::GetNome()
{
  return nome;
}

std::string Consciencia::GetDado()
{
  return dado;
}

void Consciencia::Imprime()
{
  std::cout << nome << " " << dado << std::endl;
}