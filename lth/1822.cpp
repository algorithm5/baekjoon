#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  unordered_map<int, int> b;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i)
  {
    int temp;
    scanf("%d", &temp);
    b[temp] = 1;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i)
  {
    if (!b.count(a[i]))
    {
      ans.push_back(a[i]);
    }
  }
  printf("%d\n", ans.size());
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i)
  {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
