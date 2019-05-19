#include <iostream>
using namespace std;

long long result[10];
void calc(long long n, long long digit){
	while(n>0){
		result[n%10]+=digit;
		n=n/10;
	}
}

int main(void){
	long long start=1;
	long long end;
	long long digit=1; 
	cin>>end;
	while(start<=end){
		while(start%10!=0 && start<= end){
			calc(start, digit);
			start++;
		}
		if(start>end)break;
		while(end%10!=9 && start<= end){
			calc(end, digit);
			end--;
		}
		long long count = (end/10 - start/10 + 1);
		for(int i=0; i<10; i++){
			result[i] += count*digit;
		}
		start = start/10;
		end = end/10;
		digit = digit*10LL;
	}
	for(int i=0; i<10; i++){
		cout<<result[i]<<" ";		
	}
	cout << endl;
}
