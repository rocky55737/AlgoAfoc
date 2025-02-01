#include <iostream>

double find_max_in_double_arr(double *double_arr, int len)
{
  double max = double_arr[0];
  for (int cnt = 1; cnt < len; cnt++)
  {
    if (max < double_arr[cnt])
      max = double_arr[cnt];
  }
  return max;
}

double *map_new_score(double *score_arr, int max_score, int arr_len)
{
  double *new_score_arr = new double[arr_len];
  for (int cnt = 0; cnt < arr_len; cnt++)
    new_score_arr[cnt] = score_arr[cnt] / max_score * 100;
  return new_score_arr;
}

double find_sum_double_arr(double *double_arr, int len)
{
  double sum = 0;

  for(int cnt = 0; cnt < len; cnt++)
    sum += double_arr[cnt];

  return sum;
}

double find_avg_double_arr(double *double_arr, int len)
{
  return find_sum_double_arr(double_arr, len) / len;
}

int main() 
{
  int subject_num;
  int max_score = 0;

  std::cin >> subject_num;

  double *score = new double[subject_num];

  for (int cnt = 0; cnt < subject_num; cnt++)
    std::cin >> score[cnt];

  max_score = find_max_in_double_arr(score, subject_num);

  double *new_score = map_new_score(score, max_score, subject_num);

  std::cout.precision(10);
  std::cout << find_avg_double_arr(new_score, subject_num) << std::endl;

  delete score;
  delete new_score;
  return 0;
}