#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int parent[10001];

//부모 노드 찾는 함수, 재귀적으로 root를 찾게 되어있다.
int find_k(int node)
{
  if (parent[node] == node) //무한 루프 방지
    return node;
  parent[node] = find_k(parent[node]);
  return parent[node];
}

//두 노드를 합하는 함수
bool union_k(int node_a, int node_b)
{
  int parent_a, parent_b;
  parent_a = find_k(node_a);
  parent_b = find_k(node_b);
  if (parent_a != parent_b)
  {
    parent[max(parent_a, parent_b)] = min(parent_a, parent_b); //합칠 때 기준: 작은 노드가 부모가 되도록 연결(반대로 해도 됨)
    return true;
  }
  return false;
}

struct cmp
{
  bool operator()(tuple<int, int, int>& e1, tuple<int, int, int> e2)
  {
    return get<2>(e1) > get<2>(e2);
  }
};


int main()
{
  int V, E;
  cin >> V >> E;
  //priority_queue는 우선순위 큐, cmp를 통해 원하는 식으로 큐의 정렬 기준을 결정.
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, cmp> edges_queue;
  for (int i = 0; i < E; i++)
  {
    int node1, node2, weight;
    cin >> node1 >> node2 >> weight;
    edges_queue.push(make_tuple(node1, node2, weight));
  }
  //initialize
  for (int i = 0; i <= V; i++) // 모든 노드가 연결되지 않음을 표현하기 위해 자기 자신을 부모로 설정
  {
    parent[i] = i;
  }
  //핵심코드
  int edge_cnt = 0, total_weight = 0;
  while (!edges_queue.empty() && edge_cnt < V - 1) //모든 노드가 한 번 씩만 연결되면 되므로 필요한 간선의 수는 딱 노드 수(V) - 1 개 이다.
  {
    tuple<int, int, int> now_edge = edges_queue.top();
    edges_queue.pop();
    if (union_k(get<0>(now_edge), get<1>(now_edge))) //true일 경우 tree에 연결함
    {
      edge_cnt++;
      total_weight += get<2>(now_edge);
    }
  }
  cout << total_weight << "\n";
  return 0;
}