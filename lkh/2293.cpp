#include <iostream>

using namespace std;

int main()
{
	int dp[10001] = { 1 };
	int coin_arr[101];

	int n;
	int k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> coin_arr[i];

	for (int i = 0; i < n; i++)
		for (int j = coin_arr[i]; j <= k; j++)
			dp[j] += dp[j - coin_arr[i]];

	cout << dp[k];

}