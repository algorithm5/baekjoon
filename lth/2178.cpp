#include <stdio.h>
#include <queue>
#include <tuple>

using namespace std;

int map[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      scanf("%1d", &map[i][j]);
    }
  }
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  map[0][0] = 2;
  while (!q.empty())
  {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (map[nx][ny] == 1)
      {
        q.push(make_pair(nx, ny));
        map[nx][ny] = map[x][y] + 1;
      }
    }
  }
  printf("%d\n", map[n - 1][m - 1] - 1);
}