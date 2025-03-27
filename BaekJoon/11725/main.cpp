#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;
  std::vector<std::vector<int>> tree(N);
  for (int i = 0; i < N - 1; i++)
  {
    int node1, node2;
    std::cin >> node1 >> node2;
    tree[node1 - 1].push_back(node2 - 1);
    tree[node2 - 1].push_back(node1 - 1);
  }
  std::vector<bool> visited_vector(N, false);
  std::vector<int> parent_vertex_vector(N, 0);
  std::queue<int> to_visit_queue;
  to_visit_queue.push(0);
  visited_vector[0] = true;
  while (!to_visit_queue.empty())
  {
    auto vertex_parent = to_visit_queue.front();
    to_visit_queue.pop();
    for (auto vertex_child : tree[vertex_parent])
    {
      if (!visited_vector[vertex_child])
      {
        visited_vector[vertex_child] = true;
        parent_vertex_vector[vertex_child] = vertex_parent + 1;
        to_visit_queue.push(vertex_child);
      }
    }
  }
  std::ostringstream buffer;
  for (int i = 1; i < N; i++) {
    buffer << parent_vertex_vector[i] << "\n";
  }
  std::cout << buffer.str();
  return 0;
}