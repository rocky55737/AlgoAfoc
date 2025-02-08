#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  int n;
  std::cin >> n;
  std::vector<std::pair<int, std::string>> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::stable_sort(v.begin(), v.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.first < b.first;
  });
  for (int i = 0; i < n; i++) {
    std::cout << v[i].first << ' ' << v[i].second << '\n';
  }
  return 0;
}