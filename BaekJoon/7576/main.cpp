#include <iostream>
#include <vector>
#include <queue>

int main() 
{
  int M, N;
  std::cin >> M >> N;
  std::vector<std::vector<int>> vector_box(N, std::vector<int>(M));
  std::queue<std::pair<int, std::pair<int, int>>> queue_riping_tomato;
  int unripen_tomato = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      int tomato;
      std::cin >> tomato;
      vector_box[i][j] = tomato;
      if (tomato == 1)
      {
        queue_riping_tomato.push({0, {i, j}});
      }
      else if (tomato == 0)
      {
        unripen_tomato++;
      }
    }
  }

  int day = 0;
  int y[4] = {1, -1, 0, 0};
  int x[4] = {0, 0, 1, -1};
  while (!queue_riping_tomato.empty())
  {
    int date_now = queue_riping_tomato.front().first;
    std::pair<int, int> tomato_now = queue_riping_tomato.front().second;
    queue_riping_tomato.pop();
    for (int i = 0; i < 4; i++)
    {
      if ((tomato_now.first + y[i] > -1 && tomato_now.first + y[i] < N) && (tomato_now.second + x[i] > -1 && tomato_now.second + x[i] < M) && vector_box[tomato_now.first + y[i]][tomato_now.second + x[i]] == 0)
      {
        queue_riping_tomato.push({date_now + 1, {tomato_now.first + y[i], tomato_now.second + x[i]}});
        vector_box[tomato_now.first + y[i]][tomato_now.second + x[i]] = 1;
        unripen_tomato--;
        if (date_now + 1 > day)
        {
          day = date_now + 1;
        }
      }
    }
  }
  
  if (unripen_tomato > 0)
  {
    std::cout << "-1" << std::endl;
  }
  else
  {
    std::cout << day << std::endl;
  }
  return 0;
}