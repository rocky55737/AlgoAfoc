#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N, 0), b(N, 0), c(N, 0), d(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<int> sum_ab, sum_cd;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      sum_ab.push_back(a[i] + b[j]);
      sum_cd.push_back(c[i] + d[j]);
    }
  }
  sort(sum_cd.begin(), sum_cd.end());
  unsigned long long zero_num = 0;
  for (int i = 0; i < N * N; i++)
  {
    if (lower_bound(sum_cd.begin(), sum_cd.end(), -sum_ab[i]) != sum_cd.end())
    {
      zero_num += (upper_bound(sum_cd.begin(), sum_cd.end(), -sum_ab[i]) - lower_bound(sum_cd.begin(), sum_cd.end(), -sum_ab[i]));
    }
  }
  cout << zero_num << "\n";
  return 0;
}