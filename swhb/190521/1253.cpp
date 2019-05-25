#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	cin>>n;
	long long input[n];	
	for(int i=0; i<n; i++){
		cin>>input[i];
	}
	sort(input, input+n);
	int result = 0;
	for(int i=0; i<n; i++){
		int start = 0, end = n-1;
		while(start<end){
			long long target = input[start]+input[end];
			if(target<input[i]){
				start++;
			} else if(target>input[i]){
				end--;
			} else {
				if(start!=i && end!=i){
					result++;
					break;
				}
				if(start==i){
					start++;
				}else if(end==i){
					end--;
				}
			}
		}
	}
	
	cout<<result<<endl;
}
