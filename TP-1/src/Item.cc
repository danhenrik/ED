#include "Item.h"

Item::Item()
{
  value = -1;
}

Item::Item(std::string v)
{
  value = v;
}

void Item::SetValue(std::string v)
{
  value = v;
}

std::string Item::GetValue()
{
  return value;
}

void Item::Imprime()
{
  std::cout << value << std::endl;
}