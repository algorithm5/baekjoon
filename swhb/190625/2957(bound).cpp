#include <iostream>
#include <map>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<int, long long int> arr;
	map<int, long long int>::iterator lower_bound, upper_bound;		// lower_bound를 가리키는 Iterator 

	int n;
	cin>>n; 
	
	// 초기값 주기 
	arr.insert(pair<int, long long int>(0,-1));	
	arr.insert(pair<int, long long int>(n+1,-1));
	
	// Count를 재는 수 
	long long count =0;
		
	int tmp;
	for(int i=0; i<n; i++){
		cin>>tmp;
		lower_bound = (--arr.lower_bound(tmp));		// tmp보다 작지 않은 최초의 수 
		upper_bound = (arr.upper_bound(tmp));		// tmp보다 큰 최초의 수 
		cout << max(lower_bound->second, upper_bound->second) << "MAX\n";
		long long int depth = max(lower_bound->second, upper_bound->second)+1;
		
		arr.insert(pair<int, long long int>(tmp, depth));
		cout << depth << "depth\n";
		count+=depth; 
		cout<<count<<"\n";
	}
}
