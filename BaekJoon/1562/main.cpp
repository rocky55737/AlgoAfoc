#include <iostream>

using namespace std;

int stair_arr[101][11][1025];

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i < 10; i++)
  {
    stair_arr[0][i][1 << i] = 1;
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k < 1024; k++)
      {
        if (j > 0)
          stair_arr[i + 1][j - 1][k | 1 << (j - 1)] = (stair_arr[i + 1][j - 1][k | 1 << (j - 1)] + stair_arr[i][j][k]) % 1000000000;
        if (j < 9)
          stair_arr[i + 1][j + 1][k | 1 << (j + 1)] = (stair_arr[i + 1][j + 1][k | 1 << (j + 1)] + stair_arr[i][j][k]) % 1000000000;
      }
    }
  }

  int sum_stair = 0;
  for (int i = 0; i < 10; i++)
  {
    sum_stair = (sum_stair + stair_arr[N - 1][i][1023]) % 1000000000;
  }
  cout << sum_stair << "\n";
  return 0;
}