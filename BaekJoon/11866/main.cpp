#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  int n, k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = i + 1;
  }
  std::cout << "<";
  int index = 0;
  while(v.size() >= 1)
  {
    index = (index + k - 1) % v.size();
    if (v.size() == 1) {
      std::cout << v[index];
      v.erase(v.begin() + index);
      break;
    }
    std::cout << v[index] << ", ";
    v.erase(v.begin() + index);
  }
  std::cout << ">";
  return 0;
}