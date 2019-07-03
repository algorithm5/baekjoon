#include <iostream>
#include <map>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<int, long long int> arr;
	map<int, long long int>::iterator lower_bound, upper_bound;		// lower_bound�� ����Ű�� Iterator 

	int n;
	cin>>n; 
	
	// �ʱⰪ �ֱ� 
	arr.insert(pair<int, long long int>(0,-1));	
	arr.insert(pair<int, long long int>(n+1,-1));
	
	// Count�� ��� �� 
	long long count =0;
		
	int tmp;
	for(int i=0; i<n; i++){
		cin>>tmp;
		lower_bound = (--arr.lower_bound(tmp));		// tmp���� ���� ���� ������ �� 
		upper_bound = (arr.upper_bound(tmp));		// tmp���� ū ������ �� 
		cout << max(lower_bound->second, upper_bound->second) << "MAX\n";
		long long int depth = max(lower_bound->second, upper_bound->second)+1;
		
		arr.insert(pair<int, long long int>(tmp, depth));
		cout << depth << "depth\n";
		count+=depth; 
		cout<<count<<"\n";
	}
}
