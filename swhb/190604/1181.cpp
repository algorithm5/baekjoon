#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(string &a, string &b){
	if(a.size()==b.size())return a>b;
	return a.size()>b.size();
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<string> v;
	int n;
	cin>>n;
	string s;
	
	for(int i=0; i<n; i++){
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), comp);
	
	s = v.back();
	cout << s << endl;
	v.pop_back();
	while(!v.empty()){
		if(s!=v.back() && v.back()!=""){
			cout << v.back() << endl;	
		}
		s = v.back();
		v.pop_back();		
	}
}
