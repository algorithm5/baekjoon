#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef vector<vector<unsigned long long> > matrix;

matrix operator*(matrix &a, matrix &b)
{
    unsigned long long x = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    unsigned long long y = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    unsigned long long z = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    unsigned long long w = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    x %= 1000000007;
    y %= 1000000007;
    z %= 1000000007;
    w %= 1000000007;

    matrix ret = { { x,y },{ z,w } };
    return ret;
}

void power(matrix &F, unsigned long long n){
    if (n <= 1) return;
    matrix E = { { 1, 1 },{ 1, 0 } };
    power(F, n / 2);
    F = F * F;
    if (n % 2 != 0) {
        F = F * E;
    }
}

unsigned long long fib(unsigned long long n)
{
    matrix F = { { 1, 1 },{ 1, 0 } };
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
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
	cout << fib(gcdResult);
	return 0;
}
