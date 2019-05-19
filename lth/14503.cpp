#include <stdio.h>
#include <tuple>

using namespace std;

int n, m;
int map[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int clean(int x, int y, int d)
{
  map[x][y] = -1;
  int origin = d;
  for (int i = 0; i < 4; ++i)
  {
    d -= 1;
    if (d < 0)
      d = 3;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
      continue;
    if (map[nx][ny] == 0)
    {
      return 1 + clean(nx, ny, d);
    }
  }
  d = (origin + 2) % 4;
  int nx = x + dx[d];
  int ny = y + dy[d];
  if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 1)
  {
    return clean(nx, ny, origin);
  }
  return 1;
}
int main()
{
  scanf("%d %d", &n, &m);
  int x, y, d;
  scanf("%d %d %d", &x, &y, &d);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      scanf("%d", &map[i][j]);
    }
  }
  printf("%d\n", clean(x, y, d));
}
