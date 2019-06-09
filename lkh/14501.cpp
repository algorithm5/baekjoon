#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int dp[16] = { 0 };
	int t[16];
	int p[16];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];

	for (int i = 0; i < n; i++) {
		if (dp[i + t[i]] < dp[i] + p[i])
			dp[i + t[i]] = dp[i] + p[i];

		for (int j = i + 1; j < n + 1; j++) 
			dp[j] = max(dp[i], dp[j]);
	}

	cout << dp[n];
}