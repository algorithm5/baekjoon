#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
  int N, M;
  scanf("%d %d", &N, &M);
  int minOne = 1000;
  int minSix = 1000;
  for (int i = 0; i < M; ++i)
  {
    int one, six;
    scanf("%d %d", &six, &one);
    minOne = min(one, minOne);
    minSix = min({six, minSix, minOne * 6});
  }
  printf("%d\n", (N / 6) * minSix + (N % 6 > 0) * min(minSix, minOne * (N % 6)));
}
