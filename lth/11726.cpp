#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int ppp = 1;
  int pp = 1;
  int p = 2;
  for (int i = 3; i <= n; ++i)
  {
    int temp = p;
    p = (pp * 2 + ppp) % 10007;
    ppp = pp;
    pp = temp;
  }
  if (n == 1)
    printf("%d\n", 1);
  else
    printf("%d\n", p);
}
