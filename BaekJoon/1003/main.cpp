#include <iostream>

int count[40][2];

int getZeroCount(int n) {
  if (n == 0) {
    return count[0][0];
  } else if (n == 1) {
    return count[1][0];
  }
  if (count[n][0] == 0) {
    count[n][0] = getZeroCount(n - 1) + getZeroCount(n - 2);
  }
  return count[n][0];
}

int getOneCount(int n) {
  if (n == 0) {
    return count[0][1];
  } else if (n == 1) {
    return count[1][1];
  }
  if (count[n][1] == 0) {
    count[n][1] = getOneCount(n - 1) + getOneCount(n - 2);
  }
  return count[n][1];
}

int main() 
{
  int T;
  std::cin >> T;
  count[0][0] = 1;
  count[0][1] = 0;
  count[1][0] = 0;
  count[1][1] = 1;
  for (int i = 0; i < T; i++) {
    int n;
    std::cin >> n;
    std::cout << getZeroCount(n) << " " << getOneCount(n) << std::endl;
  }
  return 0;
}