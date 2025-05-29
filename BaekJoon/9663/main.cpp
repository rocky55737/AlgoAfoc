#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool canPlace(int limit, int level, int x_pos, vector<pair<int, int> > &queens_vector)
{
  if (level == 0)
  {
    return true;
  }

  for (auto placed_queen : queens_vector)
  {
    auto [placed_queen_x, placed_queen_y] = placed_queen;
    //세로 체크
    if (placed_queen_x == x_pos)
    {
      return false;
    }
    //대각 체크
    if (abs(placed_queen_x - x_pos) == abs(placed_queen_y - level))
    {
      return false;
    }
  }
  return true;
}

int NQueen(int limit, int level, vector<pair<int, int> > &queens_vector)
{
  int ans = 0;
  if (queens_vector.size() == limit)
  {
    return 1;
  }
  for (int i = 0; i < limit; i++)
  {
    if (canPlace(limit, level, i, queens_vector))
    {
      queens_vector.push_back(make_pair(i, level));
      ans += NQueen(limit, level + 1, queens_vector);
      queens_vector.pop_back();
    }
  }
  return ans;
}

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int> > queens;
  cout << NQueen(N, 0, queens) << endl;
  return 0;
}