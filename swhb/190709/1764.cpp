#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> never_heard;

bool binary(int begin, int end, string str){
	if(begin>end){
		return false;
	} else {
		int mid = (begin+end)/2;
		if(!never_heard[mid].compare(str)){
			return true;
		} else if(never_heard[mid]>str){
			return binary(begin, mid-1, str);
		} else {
			return binary(mid+1, end, str);
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin>>n>>m;
	
	never_heard.resize(n);
	
	for(int i=0; i<n; i++){
		cin>>never_heard[i];
	}
	
	sort(never_heard.begin(), never_heard.end());
	
	string str;
	vector<string> res;
	
	for(int i=0; i<m; i++){
		cin>>str;
		if(binary(0, never_heard.size()-1, str)){
			res.push_back(str);
		}
	}
	
	sort(res.begin(), res.end());
	cout<<res.size()<<'\n';
	for(int i=0; i<res.size(); i++){
		cout << res[i].c_str() << '\n';
	}
}
