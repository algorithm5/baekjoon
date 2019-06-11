#include <iostream>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int num;
	int y=0,m=0;
	for (int i=0; i<n; i++){
		cin>>num;
//		int tmp=(num-1)%30;
		int tmp=num%29;
		y+=(num/30)*10;
		if(tmp>0) y+=10;
		m+=(num/60)*15;
//		tmp=(num-1)%60;
		tmp=num%59;
		if(tmp>0) m+=15;
	}
	if(y<m) cout<<"Y " << y << endl;
	else if(y==m) cout << "Y M " << y << endl;
	else cout << "M " << m << endl;
}
