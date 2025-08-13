#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T-- > 0)
  {
    int n;
    cin >> n;
    vector<int> seleceted(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
      cin >> seleceted[i];
    }
    vector<bool> visited(n + 1, false);
    vector<bool> poped(n + 1, false);
    stack<int, deque<int> > stk;
    int size = 0;
    for (int i = 1; i < n + 1; i++)
    {
      int now = i;
      while (!visited[now])
      {
        stk.push(now);
        visited[now] = true;
        now = seleceted[now];
      }
      while (!poped[now])
      {
        int temp = stk.top();
        stk.pop();
        poped[temp] = true;
      }
      while (!stk.empty())
      {
        int temp = stk.top();
        stk.pop();
        poped[temp] = true;
        size++;
      }
    }
    cout << size << "\n";
  }
  return 0;
}