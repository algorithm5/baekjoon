#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int y = 0, m = 0;
  for (int i = 0; i < n; ++i)
  {
    int call;
    scanf("%d", &call);
    y += (call / 30 + 1) * 10;
    m += (call / 60 + 1) * 15;
  }
  if (y <= m)
    printf("%s", "Y ");
  if (m <= y)
    printf("%s", "M ");
  printf("%d\n", min(y, m));
}
