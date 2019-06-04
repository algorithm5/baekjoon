#include <stdio.h>

using namespace std;

int dp[201][201];

// dp[i][k] - 정수 k개를 더해서 합이 i가 되는 경우의 수

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  for (int i = 0; i <= N; ++i)
  {
    dp[i][1] = 1;
    for (int j = 0; j <= i; ++j)
    {
      for (int k = 1; k <= K; ++k)
      {
        dp[i][k] += dp[j][k - 1];
        dp[i][k] %= 1000000000;
      }
    }
  }
  printf("%d\n", dp[N][K]);
}
