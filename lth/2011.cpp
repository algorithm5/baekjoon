#include <iostream>
#include <string>

using namespace std;

int d[5005];

int makeNum(string s)
{
  int num = 0;
  if (s[0] >= '0' && s[0] <= '9')
  {
    num += (s[0] - '0') * 10;
  }
  if (s[1] >= '0' && s[1] <= '9')
  {
    num += (s[1] - '0');
  }
  return num;
}
int main()
{
  string s;
  cin >> s;
  s = "  " + s;
  d[0] = 1;
  d[1] = 1;
  for (int i = 2; i < s.size(); ++i)
  {
    if (s[i] >= '1' && s[i] <= '9')
    {
      d[i] += d[i - 1];
    }
    int num = makeNum(s.substr(i - 1, 2));
    if (num >= 10 && num <= 26)
    {
      d[i] += d[i - 2];
    }
    d[i] %= 1000000;
  }
  printf("%d\n", d[s.size() - 1]);
}
