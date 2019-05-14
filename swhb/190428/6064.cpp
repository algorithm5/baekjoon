#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

int gcd(int a, int b){
	if(a<b) swap(a,b);
	while(b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
int lcm(int &a, int &b){
	return (a*b)/gcd(a,b);
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); //실행속도 향상
	
	int n=0;
	cin>>n;
	for(int i=0; i<n; i++){
		int M,N,x,y;
		cin>>M>>N>>x>>y;
		int lastYear = lcm(M,N);
		while(true){
			if(x>lastYear || (x - 1) % N + 1==y) {
				break;
			}
			x+=M;
		}
		if(x>lastYear) cout<<-1<<endl;
		else cout<<x<<endl;
	}
}
