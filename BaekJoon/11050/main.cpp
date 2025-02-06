#include <iostream>

int binomial_coefficient(int n, int k) 
{
  if (k == 0 || n == k) 
  {
    return 1;
  }
  return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}

int main() 
{
  int n, k;
  std::cin >> n >> k;
  std::cout << binomial_coefficient(n, k) << std::endl;
  return 0;
}