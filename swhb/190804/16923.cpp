#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int exe_cases[26] = {0,};
//	fill_n(exe_cases, 26, -1);
	string s;
	cin>>s;
	string rev_s = s;
	for(int i=0; i<s.length(); i++){
		char tmp = s.at(i);
		int asciitmp = int(tmp)-int('a');
		exe_cases[asciitmp] = i+1;
	}
	
	if(s.size()<26){
		for(int i=0; i<26; i++){
			if(!exe_cases[i]){
				s+= (char)(i+int('a'));
				cout<<s<<"\n";
				return 0;
			}
		}
	} else {
		char s_char[s.length()];
		strcpy(s_char,s.c_str());
		if(next_permutation(s_char,s_char+27)==true){
			cout << s_char << "\n";
		} else {
			cout<<-1<<"\n";
		}
	}
}
