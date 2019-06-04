#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, K;
deque<int> trees[10][10];
queue<pair<int, int>> five;
queue<tuple<int, int, int>> dead;
int soil[10][10];
int A[10][10];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring()
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      auto it = trees[i][j].begin();
      for (it = trees[i][j].begin(); it != trees[i][j].end(); ++it)
      {
        if (soil[i][j] >= *it)
        {
          soil[i][j] -= *it;
          (*it)++;
          if (*it % 5 == 0)
          {
            five.push(make_pair(i, j));
          }
        }
        else
          break;
      }
      int deadCnt = trees[i][j].end() - it;
      for (int c = 0; c < deadCnt; ++c)
      {
        dead.push(make_tuple(i, j, trees[i][j].back()));
        trees[i][j].pop_back();
      }
    }
  }
}
void summer()
{
  while (!dead.empty())
  {
    int x, y, age;
    tie(x, y, age) = dead.front();
    dead.pop();
    soil[x][y] += age / 2;
  }
}
void fall()
{
  while (!five.empty())
  {
    int x, y;
    tie(x, y) = five.front();
    five.pop();
    for (int i = 0; i < 8; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < N)
      {
        trees[nx][ny].push_front(1);
      }
    }
  }
}
void winter()
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      soil[i][j] += A[i][j];
    }
  }
}
int count()
{
  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cnt += trees[i][j].size();
    }
  }
  return cnt;
}
int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      soil[i][j] = 5;
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < M; ++i)
  {
    int x, y, age;
    scanf("%d %d %d", &x, &y, &age);
    trees[x - 1][y - 1].push_back(age);
  }
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      sort(trees[i][j].begin(), trees[i][j].end());
    }
  }
  for (int i = 0; i < K; ++i)
  {
    spring();
    summer();
    fall();
    winter();
  }
  printf("%d\n", count());
  return 0;
}
