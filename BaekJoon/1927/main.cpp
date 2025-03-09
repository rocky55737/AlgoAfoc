#include <iostream>
#include <queue>
#include <functional>
#include <cstdio>  // For using scanf and printf

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  unsigned int n;
  std::scanf("%u", &n);  // Using scanf for faster input
  for (unsigned int i = 0; i < n; i++)
  {
    int command;
    std::scanf("%d", &command);  // Using scanf for faster input
    if (command == 0)
    {
      if (q.empty())
      {
        std::printf("0\n");  // Using printf and \n for faster output
      }
      else
      {
        std::printf("%d\n", q.top());  // Using printf for faster output
        q.pop();
      }
    }
    else
    {
      q.push(command);
    }
  }
  return 0;
}
