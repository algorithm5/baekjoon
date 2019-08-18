#include <iostream>
using namespace std;

int first_name[26] = {0};

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		first_name[(s.at(0)-'a')]++;
	}
	
	string res;
	for(int i=0; i<26; i++){
		if(first_name[i]>=5){
			res+=(i+'a');
		}
	}
	if(res.size()>0){
		cout << res << "\n";
	} else {
		cout << "PREDAJA" << "\n";
	}
}
