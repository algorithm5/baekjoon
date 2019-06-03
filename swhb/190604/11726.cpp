#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int dp[1001]={}; 
	int n;			// 2*n의 n을 받기 위한 수
	cin>>n;
	dp[0] = 1; dp[1] = 1;
	for(int i=2; i<=n; i++){
		dp[i] = (dp[i-1]+dp[i-2])%10007;
	}
	
	cout << dp[n] << endl;
}
