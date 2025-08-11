#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[1001];

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph_v_v(N + 1);
  for (int i = 0; i < M; i++)
  {
    int pd_num;
    cin >> pd_num;
    int pre_node = 0;
    for (int j = 0; j < pd_num; j++)
    {
      int node;
      cin >> node;
      if (j != 0)
      {
        indegree[node]++;
        graph_v_v[pre_node].push_back(node);
      }
      pre_node = node;
    }
  }
  queue<int> topology;
  for (int i = 1; i < N + 1; i++)
  {
    if (indegree[i] == 0)
    {
      topology.push(i);
    }
  }
  vector<int> buffer;
  while (!topology.empty())
  {
    int now = topology.front();
    topology.pop();
    buffer.push_back(now);
    for (int next : graph_v_v[now])
    {
      indegree[next]--;
      if (indegree[next] == 0)
      {
        topology.push(next);
      }
    }
  }
  if (buffer.size() == N)
  {
    for (int i = 0; i < N; i++)
    {
      cout << buffer[i] << "\n";
    }
  }
  else
  {
    cout << "0\n";
  }
  return 0;
}