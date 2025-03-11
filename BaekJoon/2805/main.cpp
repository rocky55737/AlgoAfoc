#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  int N, M;
  std::cin >> N >> M;
  std::vector<int> trees(N);
  for (int i = 0; i < N; i++)
  {
    std::cin >> trees[i];
  }

  int end = *std::max_element(trees.begin(), trees.end());
  int start = 0;
  int result = 0;
  while(end >= start)
  {
    long long mid = (start + end) / 2;
    long long wood_sum = 0;
    for(int tree : trees)
    {
      if (tree > mid)
      {
        wood_sum += (tree - mid);
      }
    }
    if (wood_sum >= M)
    {
      result = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  std::cout << result << std::endl;
  return 0;
}