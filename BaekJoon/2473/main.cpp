#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> liquid_v(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> liquid_v[i];
  }
  sort(liquid_v.begin(), liquid_v.end());
  int offset = 0, right = N - 1, left = 1;
  vector<long long> to_mix_v(4, 0);
  to_mix_v[0] = liquid_v[offset];
  to_mix_v[1] = liquid_v[left];
  to_mix_v[2] = liquid_v[right];
  to_mix_v[3] = to_mix_v[0] + to_mix_v[1] + to_mix_v[2];
  for (; offset < N - 2; offset++)
  {
    for (left = offset + 1, right = N - 1; left < right;)
    {
      long long new_mixed = liquid_v[offset] + liquid_v[left] + liquid_v[right];
      if (abs(to_mix_v[3]) > abs(new_mixed))
      {
        to_mix_v[0] = liquid_v[offset];
        to_mix_v[1] = liquid_v[left];
        to_mix_v[2] = liquid_v[right];
        to_mix_v[3] = to_mix_v[0] + to_mix_v[1] + to_mix_v[2];
      }
      if (new_mixed < 0)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
  }
  cout << to_mix_v[0] << " " << to_mix_v[1] << " " << to_mix_v[2] << "\n";
  return 0;
}