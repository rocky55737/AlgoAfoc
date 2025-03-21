#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main() 
{
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> meeting_times_vector;
  for (int i = 0; i < N; i++)
  {
    int start, end;
    std::cin >> start >> end;
    meeting_times_vector.push_back({start, end});
  }
  std::sort(meeting_times_vector.begin(), meeting_times_vector.end(), compare);

  int meeting_cnt = 0;
  std::pair<int, int> meeting_now = {-1, -1};
  for (int i = 0; i < N; i++)
  {
    if (meeting_times_vector[i].first >= meeting_now.second)
    {
      meeting_cnt++;
      meeting_now = meeting_times_vector[i];
    }
  }

  std::cout << meeting_cnt << std::endl;
  return 0;
}