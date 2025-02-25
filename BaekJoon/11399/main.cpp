#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::vector<int> individual_time;
  std::vector<int> total_waiting_time;
  int n;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int time;
    std::cin >> time;
    individual_time.push_back(time);
  }
  std::sort(individual_time.begin(), individual_time.end());

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += individual_time[i];
    total_waiting_time.push_back(sum);
  }

  sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += total_waiting_time[i];
  }

  std::cout << sum << std::endl;
  return 0;
}