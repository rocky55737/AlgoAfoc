#include <iostream>

int leastCount[1000001];

int getLeastCount(int n) {
  if (n == 1) {
    return 0;
  }
  if (leastCount[n] != 0) {
    return leastCount[n];
  }
  int result = getLeastCount(n - 1) + 1;
  if (n % 2 == 0) {
    int temp = getLeastCount(n / 2) + 1;
    if (result > temp) {
      result = temp;
    }
  }
  if (n % 3 == 0) {
    int temp = getLeastCount(n / 3) + 1;
    if (result > temp) {
      result = temp;
    }
  }
  leastCount[n] = result;
  return result;
}

int main() 
{
  int n;
  std::cin >> n;
  std::cout << getLeastCount(n) << std::endl;
  return 0;
}