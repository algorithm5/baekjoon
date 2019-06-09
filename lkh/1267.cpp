#include <iostream>

using namespace std;

int main()
{
	int n;

	int y = 0;

	int m = 0;

	cin >> n;

	int arr[21];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int temp = arr[i] / 30;

		if (arr[i] % 30 >= 0)
			y += 10;

		y += temp * 10;

		temp = arr[i] / 60;

		if (arr[i] % 60 >= 0)
			m += 15;

		m += temp * 15;
	}

	if (y == m)
		cout << "Y ";

	if (y < m)
		cout << "Y " << y;
	else
		cout << "M " << m;

}