#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int indegree[32001];

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph_v(N + 1, vector<int>());
  for (int i = 0; i < M; i++)
  {
    int start, end;
    cin >> start >> end;
    graph_v[start].push_back(end);
    indegree[end]++;
  }
  queue<int> topology_q;
  for (int i = 1; i <= N; i++)
  {
    if (indegree[i] == 0)
    {
      topology_q.push(i);
    }
  }
  while (!topology_q.empty())
  {
    int now = topology_q.front();
    topology_q.pop();
    cout << now << " ";
    for (int next : graph_v[now])
    {
      indegree[next]--;
      if (indegree[next] == 0)
      {
        topology_q.push(next);
      }
    }
  }
  cout << "\n";
  return 0;
}