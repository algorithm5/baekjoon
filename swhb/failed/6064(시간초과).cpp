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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); //����ӵ� ���
	
	int n=0;
	cin>>n;
	for(int i=0; i<n; i++){
		int ni=1, nx=1, ny=1;
		int M,N,x,y;
		cin>>M>>N>>x>>y;
		while(ni<=lcm(M,N)){
			if(nx==M) nx=1;
			else nx++;
			if(ny==N) ny=1;
			else ny++;
			ni++;
			if(nx==x&&ny==y){
				break;
			}
		}
		if(nx!=x || ny!=y) ni=-1;
		
		cout<<ni<<endl;
	}
	return 0;
}
