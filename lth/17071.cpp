#include <stdio.h>
#include <tuple>
#include <algorithm>
#include <queue>

int mv[1200];
int check[2][500001];

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int cnt = 0;
  for (int i = k; i <= 500000; i += cnt)
  {
    mv[cnt] = i;
    cnt++;
  }
  if (mv[0] == n)
  {
    printf("%d\n", 0);
    return 0;
  }
  queue<pair<int, int>> q;
  q.push(make_pair(0, n));
  check[0][n] = 1;
  while (!q.empty())
  {
    int time, pos;
    tie(time, pos) = q.front();
    q.pop();
    if (mv[time] > 500000)
    {
      break;
    }
    if (time >= cnt)
    {
      break;
    }
    if (pos == mv[time] || check[time % 2][mv[time]])
    {
      printf("%d\n", time);
      return 0;
    }
    int eoo = (time + 1) % 2;
    if (pos * 2 <= 500000 && check[eoo][pos * 2] == 0)
    {
      q.push(make_pair(time + 1, pos * 2));
      check[eoo][pos * 2] = 1;
    }
    if (pos - 1 >= 0 && check[eoo][pos - 1] == 0)
    {
      q.push(make_pair(time + 1, pos - 1));
      check[eoo][pos - 1] = 1;
    }
    if (pos + 1 <= 500000 && check[eoo][pos + 1] == 0)
    {
      q.push(make_pair(time + 1, pos + 1));
      check[eoo][pos + 1] = 1;
    }
  }
  printf("%d\n", -1);
  return 0;
}
