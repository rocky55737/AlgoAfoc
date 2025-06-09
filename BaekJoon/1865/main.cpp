#include <iostream>
#include <vector>

using namespace std;

bool relax(vector<vector<pair<int, int> > > &graph, int nodes, vector<int> &distances)
{
  bool updated = false;
  for (int now_node = 0; now_node <= nodes; now_node++)
  {
    for (auto next : graph[now_node])
    {
      auto [next_node, next_distance] = next;
      if (distances[next_node] > distances[now_node] + next_distance)
      {
        updated = true;
        distances[next_node] = distances[now_node] + next_distance;
      }
    }
  }
  return updated;
}

int main()
{
  int TC;
  cin >> TC;
  for (int program_count = 0; program_count < TC; program_count++)
  {
    int N, M, W;
    cin >> N >> M >> W;
    vector<vector<pair<int, int> > > graph(N + 1);
    for (int i = 0; i < M; i++)
    {
      int S, E, T;
      cin >> S >> E >> T;
      graph[S].push_back(make_pair(E, T));
      graph[E].push_back(make_pair(S, T));
    }
    for (int i = 0; i < W; i++)
    {
      int S, E, T;
      cin >> S >> E >> T;
      graph[S].push_back(make_pair(E, T * -1));
    }
    vector<int> distances(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
      distances[i] = 0;
    }
    for (int i = 0; i < N - 1 && relax(graph, N, distances); i++);
    if (relax(graph, N, distances))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}