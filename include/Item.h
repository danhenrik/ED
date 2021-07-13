#ifndef ITEM
#define ITEM

#include <iostream>
#include <string>

class Item
{
public:
  Item();
  Item(std::string);
  void SetChave(std::string);
  std::string GetChave();
  void Imprime();

private:
  std::string value;
};

#endif