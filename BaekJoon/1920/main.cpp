#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    std::cin >> M;
    std::vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
      std::cin >> B[i];
    }
    for (int i = 0; i < M; i++)
    {
      if (std::binary_search(A.begin(), A.end(), B[i]))
      {
        std::cout << "1\n";
      }
      else
      {
        std::cout << "0\n";
      }
    }
    return 0;
}