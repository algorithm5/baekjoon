#include <iostream>
using namespace std;
int coin[101];
int d[10001]={0};

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k;
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>coin[i];
	}
	
	d[0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			if(j>=coin[i]){
				d[j] += d[j-coin[i]];
			}
		}
	}
	
	cout << d[k] << '\n';
}
