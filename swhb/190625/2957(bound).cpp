#include <iostream>
#include <map>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<int, long long int> arr;
	map<int, long long int>::iterator lower_bound;
	map<int, long long int>::iterator upper_bound;
	
	arr.insert(pair<int, long long int>(0,-1));
	arr.insert(pair<int, long long int>(300001,-1));
	
	int n;
	cin>>n;
	
	long long count =0;
		
	int tmp;
	for(int i=0; i<n; i++){
		cin>>tmp;
		lower_bound = (--arr.lower_bound(tmp));
		upper_bound = (arr.upper_bound(tmp));
		long long int depth = max(lower_bound->second, upper_bound->second)+1;
		
		arr.insert(pair<int, long long int>(tmp, depth));
		count+=depth;
		cout<<count<<"\n";
	}
}
