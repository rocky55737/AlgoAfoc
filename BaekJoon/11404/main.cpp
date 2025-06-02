#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() 
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  int cost_map_arr[n][n];
  //initialize cost_map_arr
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        cost_map_arr[i][j] = 0;
      }
      else
      {
        cost_map_arr[i][j] = INF;
      }
    }
  }
  
  for (int i = 0; i < m; i++)
  {
    int start, end, cost;
    cin >> start >> end >> cost;
    cost_map_arr[start - 1][end - 1] = min(cost, cost_map_arr[start - 1][end - 1]);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        if (j != i && k != i && j != k)
        {
          cost_map_arr[j][k] = min(cost_map_arr[j][k], cost_map_arr[j][i] + cost_map_arr[i][k]);
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (cost_map_arr[i][j] == INF)
      {
        cout << "0 ";
      }
      else
      {
        cout << cost_map_arr[i][j] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}