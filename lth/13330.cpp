#include <stdio.h>

using namespace std;

int students[7][2];

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
  {
    int sex, grade;
    scanf("%d %d", &sex, &grade);
    students[grade][sex]++;
  }
  int ans = 0;
  for (int i = 1; i <= 6; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      ans += students[i][j] == 0 ? 0 : (students[i][j] - 1) / k + 1;
    }
  }
  printf("%d\n", ans);
}
