#include <iostream>

int CountWays(int n, int dp[]) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }
  if (dp[n] != 0) {
    return dp[n];
  }
  dp[n] = (CountWays(n - 1, dp) + CountWays(n - 2, dp)) % 10007;
  return dp[n];
}

int main() {
  int n;
  std::cin >> n;
  int dp[n + 1];
  for (int i = 0; i < n + 1; i++) {
    dp[i] = 0;
  }
  std::cout << CountWays(n,  dp) << std::endl;
  return 0;
}