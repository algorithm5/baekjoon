#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
  int n, w, L;
  scanf("%d %d %d", &n, &w, &L);
  vector<int> truck(n);
  vector<pair<int, int>> vc;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &truck[i]);
  }
  int sum = 0;
  int time = 0;
  for (int t : truck)
  {
    if (vc.size() == 0)
    {
      ++time;
      sum += t;
      vc.push_back({t, 0});
      continue;
    }
    while (1)
    {
      ++time;
      for (pair<int, int> &v : vc)
      {
        v.second++;
      }
      if (vc[0].second == w)
      {
        sum -= vc[0].first;
        vc.erase(vc.begin());
      }
      if (sum + t <= L)
      {
        sum += t;
        vc.push_back({t, 0});
        break;
      }
    }
  }
  printf("%d\n", time + w);
}
