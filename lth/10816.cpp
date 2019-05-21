#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }
  sort(nums.begin(), nums.end());
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int temp;
    scanf("%d", &temp);
    auto low = lower_bound(nums.begin(), nums.end(), temp);
    auto up = upper_bound(nums.begin(), nums.end(), temp);

    printf("%d ", up - low);
  }
  printf("\n");
}