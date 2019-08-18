#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	
	int compareN = n;
	int cnt = 0;
	
	while(true){
		int tmp = 0;
		int fir = compareN%10;
		if(compareN >= 10){
			tmp = compareN/10;
		}
		compareN = tmp+fir;
		compareN %= 10;
		compareN += fir*10;
		cnt++;
		if(n==compareN) break;
	}
	cout<<cnt << "\n";
}
