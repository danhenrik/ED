#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <stack>

int main()
{
  std::string str;
  std::getline(std::cin, str);
  std::list<char> posfixed;
  std::stack<char> symbols;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '*' || str[i] == '+')
    {
      symbols.push(str[i]);
    }
    else if (str[i] - '0' >= -1 && str[i] - '0' <= 9)
    {
      posfixed.push_front(str[i]);
    }
    else if (str[i] == ')')
    {
      char symbol = symbols.top();
      symbols.pop();
      posfixed.push_front(symbol);
    }
  }
  while (!posfixed.empty())
  {

    std::cout << " " << posfixed.back();
    posfixed.pop_back();
  }
  return 0
}