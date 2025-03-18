#include <iostream>
#include <vector>

int MoveMultiple(int pos)
{
  if (pos <= 50000)
  {
    return (pos * 2);
  }
  return -1;
}

int MovePlus(int pos)
{
  if (pos < 100000)
  {
    return (pos + 1);
  }
  return -1;
}

int MoveMinus(int pos)
{
  return (pos - 1);
}

int BFSGetLeastMove(int arr[100001], int start, int end, int (*MvFunc[3])(int))
{
  if (start == end)
    return 0;
  int mv_cnt = 0;
  int mv_cnt_arr[100001] = {0, };
  std::vector<std::vector<int>> pos_vector_pool;
  std::vector<int> inital_move_pos;
  inital_move_pos.push_back(start);
  pos_vector_pool.push_back(inital_move_pos);
  while (1)
  {
    mv_cnt++;
    std::vector<int> v;
    pos_vector_pool.push_back(v);
    for (int pos : pos_vector_pool[mv_cnt - 1])
    {
      for (int i = 0; i < 3; i++)
      {
        int temp = MvFunc[i](pos);
        if (temp >= 0 && temp <= 100000)
        {
          if (mv_cnt_arr[temp] == 0)
          {
            if (temp == end)
            {
              return mv_cnt;
            }
            mv_cnt_arr[temp] = mv_cnt;
            pos_vector_pool[mv_cnt].push_back(temp);
          }
        }
      }
    }
  }
}

int main() 
{
  int N, K;
  std::cin >> N >> K;
  int arr[100001] = {0, };
  int (*MvFunc[3])(int);
  MvFunc[0] = MoveMultiple;
  MvFunc[1] = MovePlus;
  MvFunc[2] = MoveMinus;
  std::cout << BFSGetLeastMove(arr, N, K, MvFunc) << std::endl;
  return 0;
}