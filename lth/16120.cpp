#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'P')
    {
      st.push(s[i]);
      continue;
    }
    for (int j = 0; j < 2; j++)
    {
      if (st.empty() || st.top() == 'A' || i == s.size() - 1 || s[i + 1] != 'P')
      {
        cout << "NP" << endl;
        return 0;
      }
      st.pop();
    }
  }
  if (st.size() == 1 && st.top() == 'P')
  {
    cout << "PPAP" << endl;
    return 0;
  }
  cout << "NP" << endl;
  return 0;
}
