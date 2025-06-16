#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  int V;
  cin >> V;
  vector<vector<pair<int, int> > > graph_vector(V + 1, vector<pair<int, int> >(0));
  for (int i = 0; i < V; i++)
  {
    int start_node, end_node, dist;
    cin >> start_node >> end_node;
    while (end_node != -1)
    {
      cin >> dist;
      graph_vector[start_node].push_back(make_pair(end_node, dist));
      cin >> end_node;
    }
  }
  
  queue<pair<int, int> > to_go_queue;
  to_go_queue.push(make_pair(1, 0));
  vector<int> distance_vector(V + 1, 0);
  pair<int, int> node_max_distance(0, 0);
  distance_vector[1] = -1;

  while (!to_go_queue.empty())
  {
    auto [now_node, now_distance] = to_go_queue.front();
    to_go_queue.pop();
    for (auto [next_node, next_distance] : graph_vector[now_node])
    {
      if (distance_vector[next_node] == 0)
      {
        int new_distance = now_distance + next_distance;
        distance_vector[next_node] = new_distance;
        to_go_queue.push(make_pair(next_node, new_distance));
        if (new_distance > node_max_distance.second)
        {
          node_max_distance = make_pair(next_node, new_distance);
        }
      }
    }
  }
  to_go_queue.push(make_pair(node_max_distance.first, 0));
  fill(distance_vector.begin(), distance_vector.end(), 0);
  distance_vector[node_max_distance.first] = -1;
  node_max_distance = make_pair(0, 0);
  while (!to_go_queue.empty())
  {
    auto [now_node, now_distance] = to_go_queue.front();
    to_go_queue.pop();
    for (auto [next_node, next_distance] : graph_vector[now_node])
    {
      if (distance_vector[next_node] == 0)
      {
        int new_distance = now_distance + next_distance;
        distance_vector[next_node] = new_distance;
        to_go_queue.push(make_pair(next_node, new_distance));
        if (new_distance > node_max_distance.second)
        {
          node_max_distance = make_pair(next_node, new_distance);
        }
      }
    }
  }
  cout << node_max_distance.second << "\n";
  return 0;
}