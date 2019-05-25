#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int target[500000];
vector<int> data;

int binary(int start, int end, int count, int tar){
	int mid = (start + end)/2;
	int result;
	if(start<=end){
		if(data[mid]>tar){
			result = binary(start,mid-1, count, tar);
		} else if(data[mid]<tar){
			result = binary(mid+1, end, count, tar);
		} else {
			result = binary(start, mid-1, count, tar);
			result++;
			result+= binary(mid+1, end, count, tar);
		}
	} else {
		return count;
	}
	return result;
}

int main(void){
	int n;
	cin>>n;
	data.resize(n);
	for(int i=0; i<n; i++){
		scanf("%d",&data[i]);
	}
	sort(data.begin(), data.end());
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		scanf("%d",&target[i]);
	}

	for(int i=0; i<m; i++){
		int start = 0, end = n-1;
		int tar = target[i];
		printf("%d ", binary(start, end, 0, tar));
	}
	printf("\n");
}
