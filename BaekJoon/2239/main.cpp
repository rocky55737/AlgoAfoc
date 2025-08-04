#include <iostream>
#include <vector>
#include <string>

using namespace std;

char sudoku_g[9][9];
bool printed = false;

bool CheckSudoku(int y, int x, vector<string>& sudoku_v)
{
  char now_num = sudoku_v[y][x];
  for (int i = 0; i < 9; i++)
  {
    if ((i != x && now_num == sudoku_v[y][i]) || (i != y && now_num == sudoku_v[i][x]))
    {
      return false;
    }
  }
  int offset_y = y / 3, offset_x  = x / 3;
  for (int checking_y = 0; checking_y < 3; checking_y++)
  {
    for (int checking_x = 0; checking_x < 3; checking_x++)
    {
      if (((offset_x * 3 + checking_x != x || offset_y * 3 + checking_y != y) && now_num == sudoku_v[offset_y * 3 + checking_y][offset_x * 3 + checking_x]))
      {
        return false;
      }
    }
  }
  return true;
}

void Sudoku(int level, vector<string>& sudoku_v)
{
  if (printed)
  {
    return;
  }
  if (level == 81)
  {
    for (int i = 0; i < 9; i++)
    {
      cout << sudoku_v[i] << "\n";
    }
    printed = true;
    return;
  }
  int x = level % 9, y = level / 9;
  if(sudoku_g[y][x] != '0')
  {
    Sudoku(level + 1, sudoku_v);
  }
  else
  {
    for (char i = '1'; i < '9' + 1; i++)
    {
      sudoku_v[y][x] = i;
      if (CheckSudoku(y, x, sudoku_v))
      {
        Sudoku(level + 1, sudoku_v);
      }
      sudoku_v[y][x] = '0';
    }
  }
}

int main()
{
  vector<string> sudoku_v;
  for (int i = 0; i < 9; i++)
  {
    string str;
    cin >> str;
    if (str.size() > 11)
    {
      for (int j = 0; j < 9; j++)
      {
        sudoku_v.push_back(str.substr(j * 9, 9));
        for (int k = 0; k < 9; k++)
        {
          sudoku_g[j][k] = sudoku_v[j][k];
        }
      }
      break;
    }
    sudoku_v.push_back(str);
    for (int j = 0; j < 9; j++)
    {
      sudoku_g[i][j] = sudoku_v[i][j];
    }
  }
  Sudoku(0, sudoku_v);
  return 0;
}