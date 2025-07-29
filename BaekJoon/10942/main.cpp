#include <iostream>
#include <vector>

bool dp[2001][2001];

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
    {
      if (i == 1 && j != 0)
      {
        dp[i][j] = true;
      }
      else
      {
        dp[i][j] = false;
      }
    }
  }
  vector<int> numbers_vector(N + 1, 0);
  numbers_vector[0] = 0;
  for (int i = 1; i <= N; i++)
  {
    cin >> numbers_vector[i];
    if (numbers_vector[i] == numbers_vector[i - 1])
    {
      dp[2][i - 1] = true;
    }
    if (i > 2 && numbers_vector[i] == numbers_vector[i - 2])
    {
      dp[3][i - 2] = true;
    }
  }

  for (int i = 3; i <= N; i++)
  {
    for (int j = 1; j <= N - i + 1; j++)
    {
      if (numbers_vector[j] == numbers_vector[j + i - 1] && dp[i - 2][j + 1])
      {
        dp[i][j] = true;
      }
    }
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    int start, end;
    cin >> start >> end;
    if (dp[end - start + 1][start])
    {
      cout << "1\n";
    }
    else
    {
      cout << "0\n";
    }
  }
  return 0;
}