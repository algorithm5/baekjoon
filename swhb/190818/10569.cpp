#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
//	꼭짓점의 수 V - 모서리의 수 E + 면의 수 - 2 = 0
//	면의 수 = 2 - 꼭짓점의 수 V + 모서리의 수 E	
	for(int i=0; i<t; i++){
		int v,e;
		cin>>v>>e;
		int res = e-v+2;
		cout << res << "\n";
	}
}
