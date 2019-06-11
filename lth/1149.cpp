#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1000][3];
int rgb[1000][3];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
  }
  for (int i = 0; i < 3; ++i)
  {
    dp[0][i] = rgb[0][i];
  }
  for (int i = 1; i < n; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + rgb[i][j];
    }
  }
  printf("%d\n", min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}));
}
