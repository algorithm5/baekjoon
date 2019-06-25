#include <stdio.h>
#include <algorithm>
using namespace std;
int nums[1001];
int dp[1001];

int main()
{
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &nums[i]);
  }
  for (int i = 0; i < n; ++i)
  {
    dp[i] = 1;
    for (int j = 0; j < i; ++j)
    {
      if (nums[j] < nums[i])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}
