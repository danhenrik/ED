#include "Item.h"

Item::Item()
{
  value = -1;
}

Item::Item(std::string c)
{
  value = c;
}

void Item::SetChave(std::string c)
{
  value = c;
}

std::string Item::GetChave()
{
  return value;
}

void Item::Imprime()
{
  std::cout << value << std::endl;
}