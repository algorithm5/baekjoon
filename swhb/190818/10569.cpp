#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
//	�������� �� V - �𼭸��� �� E + ���� �� - 2 = 0
//	���� �� = 2 - �������� �� V + �𼭸��� �� E	
	for(int i=0; i<t; i++){
		int v,e;
		cin>>v>>e;
		int res = e-v+2;
		cout << res << "\n";
	}
}
