#include <iostream>
#include <vector>
#include <queue>

#define INF 2e9

int distArr[10001];

using namespace std;

void initDistanceArr(int start_node)
{
  for (int i = 0; i < 10001; i++)
  {
    distArr[i] = INF;
  }
  distArr[start_node] = 0;
  return;
}

int findFarthestNode(int start_node, vector<vector<pair<int, int> > > &tree)
{
  initDistanceArr(start_node);
  queue<pair<pair<int, int>, int> > node_to_go;
  node_to_go.push(make_pair(make_pair(start_node, 0), 0));

  while (!node_to_go.empty())
  {
    auto [now, parent] = node_to_go.front();
    auto [now_node, now_dist] = now;
    node_to_go.pop();
    for (auto next : tree[now_node])
    {
      auto [next_node, next_dist] = next;
      if (next_node == parent)
        continue;
      distArr[next_node] = now_dist + next_dist;
      node_to_go.push(make_pair(make_pair(next_node, now_dist + next_dist), now_node));
    }
  }
  
  int max = -1;
  int max_node = 0;
  for (int i = 1; i < tree.size(); i++)
  {
    if (max < distArr[i])
    {
      max = distArr[i];
      max_node = i;
    }
  }
  return max_node;
}

int main()
{
  int N;
  cin >> N;
  vector<vector<pair<int, int> > > tree(N + 1);
  for (int i = 0; i < N - 1; i++)
  {
    int start_node, end_node, weight;
    cin >> start_node >> end_node >> weight;
    tree[start_node].push_back(make_pair(end_node, weight));
    tree[end_node].push_back(make_pair(start_node, weight));
  }
  int radius_node = findFarthestNode(findFarthestNode(1, tree), tree);
  cout << distArr[radius_node] << endl;
  
  return 0;
}