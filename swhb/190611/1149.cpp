#include <iostream>
using namespace std;
typedef struct{
	int r;
	int g;
	int b;
}Cost;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	Cost dp[n];
	int red,green,blue;
	for(int i=0; i<n; i++){
		cin >> red >> green >> blue;
		
		if(i==0){
			dp[i].r = red;
			dp[i].g = green;
			dp[i].b = blue;
		} else {
			dp[i].r = min(dp[i-1].g,dp[i-1].b)+red;
			dp[i].g = min(dp[i-1].r,dp[i-1].b)+green;
			dp[i].b = min(dp[i-1].r,dp[i-1].g)+blue;
		}
	}
	
	cout << min(min(dp[n-1].r,dp[n-1].g),dp[n-1].b) << endl;
}
