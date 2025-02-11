#include <iostream>
#include <stack>
#include <string>

int main() 
{
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    std::stack<char> s;
    for (int j = 0; j < str.size(); j++)
    {
      if (str[j] == '(')
      {
        s.push(str[j]);
      }
      else if (str[j] == ')')
      {
        if (s.empty())
        {
          s.push(str[j]);
          break;
        }
        else
        {
          s.pop();
        }
      }
    }
    if (s.empty())
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}