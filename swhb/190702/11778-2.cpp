#include <iostream>
using namespace std;
unsigned long long Fibonacci(unsigned long long  n){
	if(n<=1){
		return n;
	} else {
		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
	if(a==0LL){
		return b;
	} else {
		return gcd(b%a, a);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long  n,m;
	cin>>n>>m;
	
	if(n<0LL || m<0LL){
		return 0;
	}

	unsigned long long gcdResult = gcd(n,m);
	unsigned long long fiboResult = Fibonacci(gcdResult);
	cout << fiboResult%1000000007;
	// GCD를 한 후에 Fibonacci 구하기 Fibonacci(GCD(n,m))
//	cout << "Fibonacci(GCD(n,m)) = " << (Fibonacci(gcd(n,m))%1000000007);
//	cout << (Fibonacci(gcd(n,m))%1000000007);
	return 0;
}
