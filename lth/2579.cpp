#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[301][2];
int step[301];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", &step[i]);
  }
  dp[1][0] = step[1];
  for (int i = 2; i <= n; ++i)
  {
    dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + step[i];
    dp[i][1] = dp[i - 1][0] + step[i];
  }

  printf("%d\n", max(dp[n][0], dp[n][1]));
}
