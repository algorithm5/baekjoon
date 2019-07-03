#include <iostream>
using namespace std;
unsigned long long Fibonacci(unsigned long long n){
	if(n<=1){
		return n;
	} else {
		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}

unsigned long long gcd(unsigned long long  a, unsigned long long  b){
	if(a==0LL){
		return b;
	} else {
		return gcd(b%a, a);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long n,m;
	cin>>n>>m;
	
	if(n<0 || m<0) return 0;
	// Fibonacci를 구하고 난 후에 GCD하기 => GCD(Fibonacci(n), Fibonacci(m))
//	cout << "GCD(Fibonacci(n), Fibonacci(m)) = " << (gcd(Fibonacci(n),Fibonacci(m))%1000000007) << endl;
	cout << (gcd(Fibonacci(n),Fibonacci(m))%1000000007) << endl;
	
}
