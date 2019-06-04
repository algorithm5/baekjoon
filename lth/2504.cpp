#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cal(string s, int &pos)
{
  int ans = 0;
  if (s[pos] == ')' || s[pos] == ']')
  {
    return 1;
  }
  while (pos < s.size())
  {
    if (s[pos] == ')' || s[pos] == ']')
    {
      return ans;
    }
    if (s[pos] == '(')
    {
      ans += 2 * cal(s, ++pos);
    }
    else if (s[pos] == '[')
    {
      ans += 3 * cal(s, ++pos);
    }
    ++pos;
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  int pos = 0;
  stack<char> st;
  for (char c : s)
  {
    if (c == '(' || c == '[')
    {
      st.push(c);
    }
    else
    {
      if (st.empty() || (st.top() == '(' && c != ')') || (st.top() == '[' && c != ']'))
      {
        printf("%d\n", 0);
        return 0;
      }
      st.pop();
    }
  }
  if (!st.empty())
  {
    printf("%d\n", 0);
    return 0;
  }
  printf("%d\n", cal(s, pos));
}
