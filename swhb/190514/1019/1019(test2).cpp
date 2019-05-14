#include <iostream>
using namespace std;

long long result[10];
int a,b;
void calc(int n){
	while(n>0){
		result[n%10]+=1;
		n=n/10;
	}
}

void initiate(){
}

int main(void){
	long long start;
	int a,b;
	cin>>a>>b;
	while(true){
		if(a%10==0) break;
		else{
			calc(a);
			a++;
		}
	}
	while(true){
		if(b%10==9) break;
		else{
			calc(b);
			b--;
		}
	}
	
	for(int i=a; i<=b; i++){
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
