#include <iostream>

bool is_factor(int factor, int target_num)
{
  return (target_num % factor == 0);
}

int main() 
{
  int *factors_num1 = new int[10000];
  factors_num1[0] = 1;
  int *factors_num2 = new int[10000];
  factors_num2[0] = 1;
  int temp_num;
  int num1, num2;
  int greatest_common_divisor = 1, least_common_multiple = 1;

  std::cin >> num1 >> num2;

  temp_num = num1;
  for (int cnt = 1; cnt < temp_num; cnt++)
  {
    while (is_factor(cnt + 1, temp_num))
    {
      factors_num1[cnt]++;
      temp_num /= (cnt + 1);
    }
  }
  temp_num = num2;
  for (int cnt = 1; cnt < temp_num; cnt++)
  {
    while (is_factor(cnt + 1, temp_num))
    {
      factors_num2[cnt]++;
      temp_num /= (cnt + 1);
    }
  }

  for (int cnt = 0; cnt < num1 && cnt < num2; cnt++)
  {
    if (factors_num1[cnt] != 0 && factors_num2[cnt] != 0)
    {
      for (int cnt2 = 0; cnt2 < ((factors_num1[cnt] > factors_num2[cnt]) ? factors_num2[cnt] : factors_num1[cnt]); cnt2++)
      greatest_common_divisor *= (cnt + 1);
    }
  }

  for (int cnt = 0; cnt < 10000; cnt++)
  {
    if (factors_num1[cnt] != 0 or factors_num2[cnt] != 0)
    {
      for (int cnt2 = 0; cnt2 < ((factors_num1[cnt] > factors_num2[cnt]) ? factors_num1[cnt] : factors_num2[cnt]); cnt2++)
      least_common_multiple *= (cnt + 1);
    }
  }

  std::cout << greatest_common_divisor << std::endl;
  std::cout << least_common_multiple << std::endl;

  delete[] factors_num1;
  delete[] factors_num2;
  return 0;
}