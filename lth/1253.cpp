#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  vector<int> nums;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }
  sort(nums.begin(), nums.end());
  int cnt = 0;
  for (int i = nums.size() - 1; i >= 0; --i)
  {
    int left = 0;
    int right = nums.size() - 1;
    int target = nums[i];
    while (left < right)
    {
      if (left == i)
      {
        ++left;
        continue;
      }
      if (right == i)
      {
        --right;
        continue;
      }
      long long curr = nums[left] + nums[right];
      if (curr == target)
      {
        ++cnt;
        break;
      }
      if (curr > target)
        --right;
      if (curr < target)
        ++left;
    }
  }
  printf("%d\n", cnt);
}