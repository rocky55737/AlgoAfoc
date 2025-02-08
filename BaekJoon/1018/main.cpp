#include <iostream>
#include <string>
#include <algorithm>

std::string black[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

std::string white[8] = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};

int count_diff_string(const std::string& a, const std::string& b) 
{
  int count = 0;
  int length = (a.size() < b.size()) ? a.size() : b.size();
  for (int i = 0; i < length; i++) 
  {
    if (a[i] != b[i]) 
    {
      count++;
    }
  }
  return count;
}

int count_diff_board(const std::string board[50], int x, int y) 
{
  int count_black = 0;
  int count_white = 0;
  for (int i = 0; i < 8; i++) 
  {
    count_black += count_diff_string(board[y + i].substr(x, 8), black[i]);
    count_white += count_diff_string(board[y + i].substr(x, 8), white[i]);
  }
  return std::min(count_black, count_white);
}

int main() 
{
  int n, m;
  std::cin >> n >> m;
  std::string board[50];
  for (int i = 0; i < n; i++) 
  {
    std::cin >> board[i];
  }
  int min_count = 64;
  for (int i = 0; i < n-8+1; i++) 
  {
    for (int j = 0; j < m-8+1; j++) 
    {
      min_count = std::min(min_count, count_diff_board(board, j, i));
    }
  }
  std::cout << min_count << std::endl;
  return 0;
}