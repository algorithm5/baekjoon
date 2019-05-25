#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int target[500000];
typedef struct{
	int data;
	int count;
}Point;
int main(void){
	int n;
	cin>>n;
	vector<int> data(n);
	vector<Point> countedData(n);
	for(int i=0; i<n; i++){
		scanf("%d",&data[i]);
	}
	sort(data.begin(), data.end());
	int count = 0;
	for(int i=0; i<n; i++){
		if(i==0){
			countedData[i].data=data[i];
			countedData[i].count++;
		} else if(i>0){
			if(data[i]==countedData[count].data){
				countedData[count].count++;
			} else {
				count++;
			}
		}
		
	}
	int m;
	cin>>m;
	for(int i=0; i<m; i++){
		scanf("%d",&target[i]);
	}
	int tmp = count;
	for(int i=0; i<m; i++){
		int start = 0, end = tmp-1;
		while(start<end){
			int mid = (start+end)/2;
			if(countedData[mid].data==target[i]){
				printf("%d ", countedData[mid].count);
				break;
			} else if(countedData[mid].data>target[i]){
				end=mid;
			} else if(countedData[mid].data<target[i]){
				start = mid;
			}
		}
	}
	printf("\n");
}
