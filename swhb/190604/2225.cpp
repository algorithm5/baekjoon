#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	int n,k;
	cin>>n>>k;
	long long dp[201][201];
	
	for(int i=0; i<=n; i++){
		dp[1][i] = 1;
	}
	
	for(int i=1; i<=k; i++){
		for(int j=0; j<=n; j++){
			for(int l=0; l<=j; l++){
				dp[i][j] += dp[i-1][1];
			}
			dp[i][j] %= 1000000000;
		}
	}
	cout << dp[k][n] << endl;
}
