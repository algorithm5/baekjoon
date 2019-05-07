#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
  {
    return a.first < b.first;
  }
  return a.second < b.second;
}
int main()
{
  int n;
  vector<pair<int, int>> arr;
  scanf("%d", &n);
  while (n--)
  {
    int start, end;
    scanf("%d %d", &start, &end);
    arr.push_back(make_pair(start, end));
  }
  sort(arr.begin(), arr.end(), cmp);
  int cnt = 0;
  int last = -1;
  for (pair<int, int> curr : arr)
  {
    if (curr.first >= last)
    {
      last = curr.second;
      ++cnt;
    }
  }
  printf("%d\n", cnt);
}
