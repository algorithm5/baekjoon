#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
  int n;
  scanf("%d", &n);
  memset(dp, 1000001, sizeof(dp));
  dp[1] = 0;
  for (int i = 1; i < n; ++i)
  {
    if (i * 3 <= n)
    {
      dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }
    if (i * 2 <= n)
    {
      dp[i * 2] = min(dp[i * 2], dp[i] + 1);
    }
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
  }
  printf("%d\n", dp[n]);
}