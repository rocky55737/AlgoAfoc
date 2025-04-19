#include <iostream>
#include <string>
#include <algorithm>

int cache[1001][1001];

int LCS(std::string s1, std::string s2)
{
  int i, j;
  for (i = 0; i < s1.length(); i++)
  {
    for (j = 0; j < s2.length(); j++)
    {
      if (i == 0)
      {
        if (j == 0)
        {
          if (s1[i] == s2[j])
          {
            cache[i][j] = 1;
          }
        }
        else
        {
          if (s1[i] == s2[j])
          {
            cache[i][j] = 1;
          }
          else
          {
            cache[i][j] = cache[i][j - 1];
          }
        }
      }
      else
      {
        if (j == 0)
        {
          if (s1[i] == s2[j])
          {
            cache[i][j] = 1;
          }
          else if (cache[i - 1][0] != 0)
          {
            cache[i][j] = cache[i - 1][j];
          }
        }
        else
        {
          if (s1[i] == s2[j])
          {
            cache[i][j] = cache[i - 1][j - 1] + 1;
          }
          else
          {
            cache[i][j] = std::max(cache[i][j - 1], cache[i - 1][j]);
          }
        }
      }
    }
  }
  if (i == 0 || j == 0)
  {
    return 0;
  }
  return cache[i - 1][j - 1];
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s1, s2;
  std::cin >> s1;
  std::cin >> s2;
  std::cout << LCS(s1, s2) << "\n";
  return 0;
}