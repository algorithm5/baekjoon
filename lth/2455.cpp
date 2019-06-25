#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int leave, enter, remain, ans, n = 4;
  remain = ans = 0;
  while (n--)
  {
    scanf("%d %d", &leave, &enter);
    remain += enter - leave;
    ans = max(ans, remain);
  }
  printf("%d\n", ans);
}
