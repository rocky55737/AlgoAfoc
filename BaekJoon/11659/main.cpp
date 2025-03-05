#include <iostream>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  int N, M;
  std::cin >> N >> M;
  int arr[N];
  int prefix_sum[N];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
    if (i == 0) {
      prefix_sum[i] = arr[i];
    } else {
      prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
  }
  for (int i = 0; i < M; i++) {
    int start, end;
    std::cin >> start >> end;
    if (start == 1) {
      std::cout << prefix_sum[end - 1] << '\n';
    } else {
      std::cout << prefix_sum[end - 1] - prefix_sum[start - 2] << '\n';
    }
  }
  return 0;
}