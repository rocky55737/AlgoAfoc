#include <iostream>
#include <vector>

using namespace std;

long long getCrossProduct(int x1, int y1, int x2, int y2)
{  
  return ((long long)x1 * y2 - (long long)x2 * y1);
}

int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
  long long result = getCrossProduct(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
  if (result == 0)
  {
    return 0;
  }
  else if (result > 0)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

bool isInLine(int start_x, int start_y, int end_x, int end_y, int point_x, int point_y)
{
  int min_x = min(start_x, end_x);
  int max_x = max(start_x, end_x);
  int min_y = min(start_y, end_y);
  int max_y = max(start_y, end_y);
  if ((start_x == point_x && start_y == point_y) || (end_x == point_x && end_y == point_y))
  {
    return true;
  }
  if (start_x == end_x && end_x == point_x)
  {
    //x가 모두 같으면 y로 판단
    if (min_y < point_y && max_y > point_y)
    {
      return true;
    }
  }
  if (start_y == end_y && end_y == point_y)
  {
    //y가 모두 같으면 x로 판단
    if (min_x < point_x && max_x > point_x)
    {
      return true;
    }
  }
  if ((min_y < point_y && max_y > point_y) && (min_x < point_x && max_x > point_x))
  {
    return true;
  }
  return false;
}

bool isMeetByPosition(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  if (isInLine(x1, y1, x2, y2, x3, y3))
  {
    return true;
  }
  else if (isInLine(x1, y1, x2, y2, x4, y4))
  {
    return true;
  }
  else if (isInLine(x3, y3, x4, y4, x1, y1))
  {
    return true;
  }
  return false;
}

bool isMeet(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  int firstCCW = CCW(x1, y1, x2, y2, x3, y3);
  int secondCCW = CCW(x1, y1, x2, y2, x4, y4);
  int thirdCCW = CCW(x3, y3, x4, y4, x1, y1);
  int fourthCCW = CCW(x3, y3, x4, y4, x2, y2);

  if (firstCCW == 0 && secondCCW == 0 && thirdCCW == 0 && fourthCCW == 0)
  {
    return (isMeetByPosition(x1, y1, x2, y2, x3, y3, x4, y4));
  }
  else if (firstCCW * secondCCW <= 0 && thirdCCW * fourthCCW <= 0)
  {
    return true;
  }
  return false;
}

int main()
{
  vector<pair<pair<int, int>, pair<int, int> > > pos_v(2, pair<pair<int, int>, pair<int, int>>(pair<int, int>(0, 0), pair<int, int>(0, 0)));
  for (int i = 0; i < 2; i++)
  {
    cin >> pos_v[i].first.first >> pos_v[i].first.second >> pos_v[i].second.first >> pos_v[i].second.second;
  }
  cout << isMeet(pos_v[0].first.first, pos_v[0].first.second, pos_v[0].second.first, pos_v[0].second.second, pos_v[1].first.first, pos_v[1].first.second, pos_v[1].second.first, pos_v[1].second.second) << "\n";
  return 0;
}