#include <iostream>

void NMProblem(int N, int M, int num, int level, int *buffer)
{
  if (level == M)
  {
    for (int i = 0; i < M; i++)
    {
      std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
    return;
  }
  for (int i = num; i <= N; i++)
  {
    buffer[level] = i;
    NMProblem(N, M, i + 1, level + 1, buffer);
  }
}

int main()
{
  int N, M;
  std::cin >> N >> M;
  int buffer[M];
  NMProblem(N, M, 1, 0, buffer);
  return 0;
}