#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//점화식
	//dp = A 색깔 제외한 두 색깔 중 작은 비용 + A 색깔 비용

	int n;

	int dp[3][1001] = {0};
	cin >> n;

	for (int i = 0; i < n; i++) {

		int j = i + 1;

		int r, g, b;

		cin >> r >> g >> b;

		dp[0][j] = dp[1][j - 1] > dp[2][j - 1] ? dp[2][j - 1] + r : dp[1][j - 1] + r;
		dp[1][j] = dp[0][j - 1] > dp[2][j - 1] ? dp[2][j - 1] + g : dp[0][j - 1] + g;
		dp[2][j] = dp[0][j - 1] > dp[1][j - 1] ? dp[1][j - 1] + b : dp[0][j - 1] + b;
	}

	vector<int> v;

	v.push_back(dp[0][n]);
	v.push_back(dp[1][n]);
	v.push_back(dp[2][n]);

	cout << *min_element(v.begin(), v.end());

}