#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> liquid_ph_vector(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> liquid_ph_vector[i];
  }

  vector<int>::iterator start_iter = liquid_ph_vector.begin(), end_iter = --liquid_ph_vector.end();
  pair<int, int> two_liquid_pair = make_pair(*start_iter, *end_iter);
  int min_ph = 2147483647;
  while (start_iter != end_iter)
  {
    int new_ph = *start_iter + *end_iter;
    if (abs(min_ph) > abs(new_ph))
    {
      two_liquid_pair.first = *start_iter;
      two_liquid_pair.second = *end_iter;
      min_ph = new_ph;
    }
    if (abs(*start_iter) > abs(*end_iter))
    {
      start_iter++;
    }
    else
    {
      end_iter--;
    }
  }
  cout << two_liquid_pair.first << " " << two_liquid_pair.second << "\n";
  return 0;
}