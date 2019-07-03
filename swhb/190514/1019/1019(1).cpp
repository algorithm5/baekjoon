#include <iostream>
using namespace std;
int result[10]={};

void calc(int n){
	while(n>0){
		result[n%10]+=1;
		n=n/10;
	}
}

int main(void){
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		calc(i);
	}
	for(int i=0; i<10; i++){
		cout << result[i];
		if(i!=9){
			cout << " ";
		}
	}
	cout << endl;
	
}
