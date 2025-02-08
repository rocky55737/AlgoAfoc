#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first < b.first;
  });
  for (int i = 0; i < n; i++) {
    std::cout << v[i].first << ' ' << v[i].second << '\n';
  }
  return 0;
}