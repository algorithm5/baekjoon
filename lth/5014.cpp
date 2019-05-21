#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  int F, S, G, U, D;
  scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

  vector<int> check(F + 1, -1);
  queue<int> q;
  q.push(S);
  check[S] = 0;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    if (curr == G)
      break;
    int up = curr + U;
    int down = curr - D;
    if (up <= F && check[up] == -1)
    {
      q.push(up);
      check[up] = check[curr] + 1;
    }
    if (down >= 1 && check[down] == -1)
    {
      q.push(down);
      check[down] = check[curr] + 1;
    }
  }
  if (check[G] == -1)
  {
    printf("%s\n", "use the stairs");
  }
  else
  {
    printf("%d\n", check[G]);
  }
}