#include <iostream>
using namespace std;
int main()
{
	long long dp[201][201];
	long long const cm = 1000000000;

	int n, k;
	cin >> n;
	cin >> k;
	
	//k가 1이라면 경우의 수는 항상 1이다.
	for (int i = 1; i < n+1; i++) 
		dp[i][1] = 1;

	//n이 1이라면 경우의 수는 항상 k다.
	//ex) 3 -> 0,0,1 | 0,1,0 | 1,0,0 
	for (int i = 1; i < k+1; i++)
		dp[1][i] = i;

	for (int i = 2; i < n+1; i++) 
		for (int j = 2; j < k + 1; j++) 
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % cm;
			
	cout << dp[n][k] ;

	return 0;
}