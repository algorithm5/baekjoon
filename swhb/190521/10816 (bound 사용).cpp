#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int target[500000];
int main(void){
	int n;
	cin>>n;
	vector<int> data(n);
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
		cout << upper_bound(data.begin(), data.end(), target[i]) - lower_bound(data.begin(), data.end(), target[i]) << " ";
	}
	printf("\n");
}
