#include "Item.h"

Item::Item()
{
  value = -1;
}

Item::Item(string v)
{
  value = v;
}

void Item::SetValue(string v)
{
  value = v;
}

string Item::GetValue()
{
  return value;
}

void Item::Imprime()
{
  cout << value << " ";
}