#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int nums[4][4000];
void getSum(int start, int n, vector<int> &subset)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      subset.push_back(nums[start][i] + nums[start + 1][j]);
    }
  }
  return;
}
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      scanf("%d", &nums[j][i]);
    }
  }
  vector<int> first;
  vector<int> second;

  getSum(0, n, first);
  getSum(2, n, second);

  sort(second.begin(), second.end());
  long long answer = 0;
  int size = first.size();
  for (auto curr : first)
  {
    int left = 0, right = size;
    int lower, upper;
    while (left < right)
    {
      int mid = (left + right) / 2;
      if (second[mid] < -curr)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }
    lower = right;
    left = 0;
    right = size;
    while (left < right)
    {
      int mid = (left + right) / 2;
      if (second[mid] <= -curr)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }
    upper = right;
    answer += upper - lower;
  }
  printf("%lld\n", answer);
}
