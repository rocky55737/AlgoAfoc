#include <iostream>
#include <vector>

int DP_LIS(std::vector<int> nums, int lim, int idx, std::vector<int> &length)
{
  if (length[idx] != 0)
  {
    return length[idx];
  }
  length[idx] = 1;
  for (int i = idx + 1; i < lim; i++)
  {
    int tmp = DP_LIS(nums, lim, i, length);
    if (nums[i] > nums[idx])
    {
      length[idx] = std::max(length[idx], tmp + 1);
    }
  }
  return length[idx];
}

int main() 
{
  int A;
  std::cin >> A;
  std::vector<int> Aj(A);
  for (int i = 0; i < A; i++)
  {
    std::cin >> Aj[i];
  }
  std::vector<int> length(A, 0);
  DP_LIS(Aj, A, 0, length);
  int max = -1;
  for (int i = 0; i < A; i++)
  {
    if (max < length[i])
    {
      max = length[i];
    }
  }
  std::cout << max << std::endl;
  return 0;
}