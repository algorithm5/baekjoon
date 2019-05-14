/*

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int data[10] = {0};
	
	int n;
	cin>>n;
	if(n>=0 && n<=1000000){
		if(n==0){
			data[0]++;
		}
		while(n!=0){
			int m= 0;
			m=n%10;
			n/=10;
			if(m==6 || m==9){
				if(data[6]>data[9]) {
					data[9]++;
				}
				else if(data[6]<data[9]){
					data[6]++;
				}
				else {
					data[m]++;
				}
			} else {
				data[m]++;
			}
		}
		int size=0;
	
		for(int i=0; i<10; i++){
			size = max(size,data[i]);
		}
		cout<<size<<endl;
	} else {
		cout<<"err"<<endl;
	}
}
/*

*/ 
