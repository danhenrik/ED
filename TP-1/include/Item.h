#ifndef ITEM
#define ITEM

#include <iostream>
#include <string>

class Item
{
public:
  // Cria um item vazio.
  Item();
  // Cria atribuindo a string passada ao value.
  Item(std::string);
  // Atribui a string passada ao value.
  void SetValue(std::string);
  // Retorna value.
  std::string GetValue();
  // Imprime value no terminal.
  void Imprime();

private:
  std::string value;
};

#endif