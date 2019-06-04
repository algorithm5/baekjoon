#include <iostream>

using namespace std;

int main(void) {
	int n;
	int stair_arr[301];
	int dp_arr[301];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> stair_arr[i];

	if (n == 1 ) {
		cout << stair_arr[0];
		return 0;
	}

	if (n == 2 ) {
		cout << stair_arr[0] + stair_arr[1];
		return 0;
	}

	dp_arr[0] = stair_arr[0];
	dp_arr[1] = stair_arr[0] + stair_arr[1];

	//start from first
	int a = stair_arr[2] + dp_arr[0];
	//start from second
	int b = stair_arr[2] + stair_arr[1];

	dp_arr[2] = a > b ? a : b;

	for (int i = 3; i < n; i++) {

		//jump
		a = stair_arr[i] + dp_arr[i - 2];
		//no jump
		b = stair_arr[i] + stair_arr[i - 1] + dp_arr[i - 3];

		dp_arr[i] = a > b ? a : b;
	}

	cout << dp_arr[n-1];
}
