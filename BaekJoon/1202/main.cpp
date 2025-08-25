#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct CMP_s
{
  bool operator()(pair<unsigned int, unsigned int>& a, pair<unsigned int, unsigned int>& b)
  {
    return a.second < b.second;
  }
};

int main()
{
  unsigned int N, K;
  cin >> N >> K;
  vector<pair<unsigned int, unsigned int> > jwels_v(N, pair<unsigned int, unsigned int>(0, 0));
  for (unsigned int i = 0; i < N; i++)
  {
    cin >> jwels_v[i].first >> jwels_v[i].second;
  }
  sort(jwels_v.begin(), jwels_v.end());
  vector<unsigned int> bag_v(K, 0);
  for (unsigned int i = 0; i < K; i++)
  {
    cin >> bag_v[i];
  }
  sort(bag_v.begin(), bag_v.end());
  priority_queue<pair<unsigned int, unsigned int>, vector<pair<unsigned int, unsigned int> >, CMP_s> p_q;
  unsigned long long sum = 0;
  unsigned int jwels_idx = 0;
  for (unsigned int bag : bag_v)
  {
    while (jwels_idx < N && jwels_v[jwels_idx].first <= bag)
    {
      p_q.push(jwels_v[jwels_idx]);
      jwels_idx++;
    }
    if (!p_q.empty() && p_q.top().first <= bag)
    {
      sum += p_q.top().second;
      p_q.pop();
    }
  }
  cout << sum << "\n";
  return 0;
}