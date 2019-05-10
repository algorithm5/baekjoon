



#include <iostream>
#include <algorithm>
using namespace std;
struct meeting {
	int start, end;
};

bool cmp(const meeting &a, const meeting &b){
	if(a.end == b.end) return a.start<b.start;
	else return a.end<b.end;
}
meeting arr[100000];

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i].start>>arr[i].end;
	}
	
	sort(arr, arr+n, cmp);
	int pointer = 0;
	int result = 0;
	for(int i=0; i<n; i++){
		if(pointer<=arr[i].start){
			pointer = arr[i].end;
			result += 1;
		}
	}
	
	cout<<result<<endl;
}
