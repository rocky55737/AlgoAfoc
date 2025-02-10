#include <iostream>
#include <queue>
#include <algorithm>

int main() 
{
  std::queue<int> q;
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }
  while (q.size() > 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }
  std::cout << q.front() << std::endl;
  return 0;
}