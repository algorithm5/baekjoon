#include <stdio.h>
using namespace std;
int arr[41];
int main()
{
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  arr[0] = 1;
  arr[1] = 1;
  for (int i = 2; i <= n; ++i)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  int ans = 1;
  int prev = 1;
  while (m--)
  {
    int curr;
    scanf("%d", &curr);
    ans *= (arr[curr - prev]);
    prev = curr + 1;
  }
  ans *= arr[n + 1 - prev];
  printf("%d\n", ans);
}
