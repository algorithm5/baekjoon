#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	int n;
	cin>>n;
	int data[n];
	int dp[n];
	for(int i=0; i<n; i++){
		cin>>data[i];
	}
	
	dp[0] = data[0];
	dp[1] = max(dp[0] + data[1], data[1]);
	dp[2] = max(dp[0] + data[2], data[1] + data[2]);
	for(int i=3; i<n; i++){
		dp[i] = max(dp[i-2]+data[i], dp[i-3]+data[i]+data[i-1]);
	}
	
	cout << dp[n-1] << endl;
}
