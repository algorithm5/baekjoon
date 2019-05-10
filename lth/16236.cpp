#include <stdio.h>
#include <tuple>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int map[20][20];
int check[20][20];
bool cmp(pair<int, int> a, pair<int, int> b)
{
  if (a.first == b.first)
  {
    return a.second < b.second;
  }
  return a.first < b.first;
}
tuple<int, int, int> find(int i, int j, int size)
{
  memset(check, -1, sizeof(check));
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  check[i][j] = 0;
  vector<pair<int, int>> cand;
  while (!q.empty())
  {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    if (cand.size() > 0 && check[cand[0].first][cand[0].second] < check[x][y])
    {
      break;
    }
    if (map[x][y] > 0 && map[x][y] < size)
    {
      cand.push_back(make_pair(x, y));
    }
    for (int k = 0; k < 4; ++k)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] <= size && check[nx][ny] == -1)
      {
        q.push(make_pair(nx, ny));
        check[nx][ny] = check[x][y] + 1;
      }
    }
  }
  if (cand.size() == 0)
  {
    return make_tuple(-1, -1, -1);
  }
  sort(cand.begin(), cand.end(), cmp);
  int rx, ry;
  tie(rx, ry) = cand[0];
  map[rx][ry] = 9;
  map[i][j] = 0;
  return make_tuple(rx, ry, check[rx][ry]);
}

int main()
{
  scanf("%d", &n);
  int x, y, size = 2;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 9)
      {
        x = i;
        y = j;
      }
    }
  }
  int ans = 0;
  int eat = 0;
  int cx = x, cy = y, time;
  tie(cx, cy, time) = find(cx, cy, size);
  while (time != -1)
  {
    ans += time;
    eat++;
    if (eat == size)
    {
      ++size;
      eat = 0;
    }
    tie(cx, cy, time) = find(cx, cy, size);
  }
  printf("%d\n", ans);
}
