#ifndef ITEM
#define ITEM

#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
  /* Cria um item vazio. */
  Item();
  /* Cria atribuindo a string passada ao value. */
  Item(string);
  /* Atribui a string passada ao value. */
  void SetValue(string);
  /* Retorna value. */
  string GetValue();
  /* Imprime value no terminal. */
  void Imprime();

private:
  string value;
};

#endif