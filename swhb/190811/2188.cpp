#include <iostream>
#include <queue>
using namespace std;
bool visited[200] = {false};
int house[200] = {0};

queue<int> kingu[200];
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		
		for(int j=0; j<x; j++){
			int wan_house;
			cin>>wan_house;
			kingu[i].push(wan_house-1);
			
		}
	}
	
	for(int i=0; i<n; i++){
		while(!kingu[i].empty()){
			int tmp = kingu[i].front();
			if(!visited[tmp]){
				house[tmp]=i+1;
				visited[tmp]=true;
				kingu[i].pop();
				break;
			}
		}
		
	}
	
	int res = 0;
	int max_num=0;
	for(int i=0; i<m; i++){
		if(house[i]>max_num){
			res=i+1;
			max_num=house[i];
		}
	}
	cout << max_num << "\n";
}
