#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  int n;
  std::cin >> n;
  std::vector<int> cards(n);
  for (int i = 0; i < n; i++) {
    std::cin >> cards[i];
  }
  std::sort(cards.begin(), cards.end());
  int m;
  std::cin >> m;
  std::vector<int> targets(m);
  for (int i = 0; i < m; i++) {
    std::cin >> targets[i];
  }
  for (int i = 0; i < m; i++){
    int target = targets[i];
    auto lower = std::lower_bound(cards.begin(), cards.end(), target);
    auto upper = std::upper_bound(cards.begin(), cards.end(), target);
    std::cout << upper - lower << " ";
  }
  return 0;
}
