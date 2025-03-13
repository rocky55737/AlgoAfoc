#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() 
{
  int N;
  std::cin >> N;
  std::vector<int> v(N);
  
  for (int i = 0; i < N; i++)
  {
    std::cin >> v[i];
  }
  std::vector<int> sorted_v = v;

  std::sort(sorted_v.begin(), sorted_v.end());
  sorted_v.erase(std::unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

  std::unordered_map<int, int> compressed_map;
  for (int i = 0; i < sorted_v.size(); i++)
  {
    compressed_map[sorted_v[i]] = i;
  }


  for (int i = 0; i < N; i++)
  {
    std::cout << compressed_map[v[i]] << " ";
  }
  return 0;
}