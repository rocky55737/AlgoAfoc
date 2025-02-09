#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::vector<int> a;
  std::vector<int> v;
  int n, m;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    std::cin >> temp;
    a.push_back(temp);
  }
  std::sort(a.begin(), a.end());
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }
  for (int i = 0; i < m; i++) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (a[mid] == v[i]) {
        std::cout << 1 << '\n';
        break;
      }
      else if (a[mid] < v[i]) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    if (left > right) {
      std::cout << 0 << '\n';
    }
  }
  return 0;
}