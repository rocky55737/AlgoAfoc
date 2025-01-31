#include <iostream>

bool check_palindrome(std::string str_num)
{
  int len, half_len;
  int cnt;

  len = str_num.length();
  half_len = len / 2;

  for (cnt = 0; cnt < half_len; cnt++)
  {
    if(str_num[cnt] != str_num[len - 1 - cnt])
    {
      return false;
    }
  }
  return true;
}

int main() 
{
  std::string str_num;

  std::cin >> str_num;
  while (str_num != "0")
  {
    if (check_palindrome(str_num))
      std::cout << "yes" << std::endl;
    else
      std::cout << "no" << std::endl;
    std::cin >> str_num;
  }
  return 0;
}