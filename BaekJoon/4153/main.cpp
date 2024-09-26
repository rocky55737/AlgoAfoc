#include <iostream>

int main()
{
  int a, b, c;
  
  std::cin >> a >> b >> c;
  while (a != 0 && b != 0 && c != 0)
  {
    if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
      std::cout << "right" << std::endl;
    else
      std::cout << "wrong" << std::endl;
    std::cin >> a >> b >> c;
  }
  return 0;
}