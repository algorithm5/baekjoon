#include <iostream>
using namespace std;

typedef struct{
	int day;
	int cost;
}Cons;

Cons list[15];
int dp[16];

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin>>list[i].day>>list[i].cost;
	}
	
	for(int i=n-1; i>=0; i--){
		int target = i+list[i].day;
		if(target>n){
			dp[i] = dp[i+1];
		} else {
			dp[i] = max(dp[i+1], dp[target]+list[i].cost);
		}
	}
	
	cout<<dp[0]<<endl;
}
