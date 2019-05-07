#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int nums[100000];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &nums[i]);
  }
  int ans = INT_MIN, sum = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    sum = sum < 0 ? nums[i] : sum + nums[i];
    ans = max(ans, sum);
  }
  printf("%d\n", ans);
}
