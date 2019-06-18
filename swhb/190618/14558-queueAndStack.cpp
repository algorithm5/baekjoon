#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct{
	long long data;
	int num;
}Shoes;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	int count = 0;
	long long total = 0;
	cin>>n>>m;
	
	if(n==0 || n==1){
		if(m>0){
			cout << -1 << endl;
			return 0;
		}
	}
	
	queue<Shoes> totalInput;
	queue<Shoes> mainData;
	stack<Shoes> tmpset;
	
	long long _m[m];
	
	
	for(int i=0; i<n; i++){
		long long tmp = 0;
		cin>>tmp;
		total+=tmp;
		Shoes input;
		input.data = tmp;
		input.num = i+1;
		totalInput.push(input);
	}
	
	mainData = totalInput;
	
	for(int i=0; i<m; i++){
		cin>>_m[i];
	}
	
	long long calcData = 0;
	int countFor = 0;
	int nx =0;
	int resultset[n];
	for(int i=0; i<m; ){
		if(_m[i]==calcData+mainData.front().data){
			if(countFor+1==n){
				cout << -1 << endl;
				return 0;
			}else {
				tmpset.push(mainData.front());
				mainData.pop();
			}
		} else {
			if(!mainData.empty()){
				calcData+=mainData.front().data;
				resultset[countFor]=mainData.front().num;
				countFor++;
				mainData.pop();
			}
		} 
		
	
		if(!tmpset.empty()){
			if(_m[i]==calcData+tmpset.top().data){
//				mainData.push(tmpset.top());
//				tmpset.pop();
			} else {
				if(!tmpset.empty()){
					calcData+=tmpset.top().data;
					resultset[countFor]=tmpset.top().num;
					countFor++;
					tmpset.pop();
				}
			}
		}
		
		if(_m[i]<calcData) i++;
		
		if(total==calcData) {
			if(total==_m[i]){
				cout << -1 << endl;
				return 0;
			}
			break;
		}
	}
	
	for(int i=0; i<n; i++){
		cout << resultset[i] << " ";
	}
}
