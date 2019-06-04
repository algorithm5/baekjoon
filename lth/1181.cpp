#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
  if (a.size() == b.size())
  {
    return a < b;
  }
  return a.size() < b.size();
}
int main()
{
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), cmp);
  string prev;
  for (string s : v)
  {
    if (s == prev)
    {
      continue;
    }
    cout << s << endl;
    prev = s;
  }
}
