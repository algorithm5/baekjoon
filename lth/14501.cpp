#include <stdio.h>
#include <tuple>
#include <algorithm>

using namespace std;

int dp[16];
pair<int, int> days[16];

int main()
{
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    int day, money;
    scanf("%d %d", &day, &money);
    days[i] = make_pair(day, money);
  }
  for (int i = 1; i <= n; ++i)
  {
    for (int j = i - 1; j >= 1; --j)
    {
      if (j + days[j].first - 1 < i)
      {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    if (i + days[i].first - 1 <= n)
    {
      dp[i] += days[i].second;
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}
