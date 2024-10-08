#include <iostream>

int isPrime(int n)
{
  int i;
  if (n <= 1)
    return 0;
  for (i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() 
{
  int rotate;
  int num;
  int num_prime = 0;

  std::cin >> rotate;
  for(int i = 0; i < rotate; i++)
  {
    std::cin >> num;
    if (isPrime(num))
      num_prime++;
  }
  std::cout << num_prime << std::endl;
  return 0;
}