#include <iostream>
#include <algorithm>
using namespace std;

char board[50][50];
int n;
int check(int sr, int er, int sc, int ec)
{
  int maxL = 1;
  for (int i = sr; i <= er; ++i)
  {
    int len = 1;
    char pre = board[i][0];
    for (int j = 1; j < n; ++j)
    {
      if (board[i][j] == pre)
      {
        ++len;
        maxL = max(maxL, len);
      }
      else
      {
        pre = board[i][j];
        len = 1;
      }
    }
  }
  for (int i = sc; i <= ec; ++i)
  {
    int len = 1;
    char pre = board[0][i];
    for (int j = 1; j < n; ++j)
    {
      if (board[j][i] == pre)
      {
        ++len;
        maxL = max(maxL, len);
      }
      else
      {
        pre = board[j][i];
        len = 1;
      }
    }
  }
  return maxL;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> board[i][j];
    }
  }
  int maxL = check(0, n - 1, 0, n - 1);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 1; j < n; ++j)
    {
      swap(board[i][j - 1], board[i][j]);
      maxL = max(maxL, check(i, i, j - 1, j));
      swap(board[i][j - 1], board[i][j]);
      swap(board[j - 1][i], board[j][i]);
      maxL = max(maxL, check(j - 1, j, i, i));
      swap(board[j - 1][i], board[j][i]);
    }
  }
  cout << maxL << endl;
}
