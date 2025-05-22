#include <iostream>
#include <vector>

int main()
{
  int N, K;
  std::cin >> N >> K;
  std::vector<int> Weight(N, 0);
  std::vector<int> Value(N, 0);
  for (int i = 0; i < N; i++)
  {
    std::cin >> Weight[i] >> Value[i];
  }
  std::vector<int> dp(K + 1, 0);

  for (int i = 0; i < N; i++)
  {
    for (int j = K; j >= Weight[i]; j--)
    {
      dp[j] = std::max(dp[j], dp[j - Weight[i]] + Value[i]);
    }
  }
  std::cout << dp[K] << std::endl;
  return 0;
}