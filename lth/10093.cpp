#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  long long A, B;
  cin >> A >> B;

  if (A > B)
    swap(A, B);
  if (A != B)
  {

    cout << B - A - 1 << endl;
    for (long long i = A + 1; i < B; i++)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  else
    cout << 0 << endl;
  return 0;
}
