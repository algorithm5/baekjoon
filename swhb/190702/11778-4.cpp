#include <iostream>
#include <map>

using namespace std;

map<long long, long long> d;
const long long mod = 1000000007LL;

unsigned long long fib(unsigned long long n)
{
    if (n <= 0) {
        return 0;
    } else if (n <= 2) {
        return 1;
    } else if (d.count(n) > 0) {
        return d[n];
    } else {
        if (n % 2 == 1) {
            long long m = (n+1) / 2;
            long long t1 = fib(m);
            long long t2 = fib(m-1);
            d[n] = t1*t1 + t2*t2;
            return d[n];
        } else {
            long long m = n/2;
            long long t1 = fib(m-1);
            long long t2 = fib(m);
            d[n] = (2LL*t1 + t2)*t2;
            return d[n];
        }
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
	cout << fib(gcdResult) << endl;
	cout << fib(gcdResult)%mod;
	return 0;
}
