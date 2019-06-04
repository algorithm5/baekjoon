#include <iostream>
#include <stack>
using namespace std;

int main(void){
	//scanf 동기화 제거 
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	string s;
	cin >> s;
	stack<char> tmp;
	int tmpScore = 1;
	int score = 0;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='('){
			tmpScore*=2;
			tmp.push(s[i]);
		}else if(s[i]=='['){
			tmpScore*=3;
			tmp.push(s[i]);
		} else if(s[i]==')'){
			if(tmp.empty() || tmp.top()!='('){
				score=0;
				break;
			} else {
				if(s[i-1]=='('){
					score += tmpScore;	
				}
				tmpScore /= 2;
				tmp.pop();
			}
		} else if(s[i]==']'){
			if(tmp.empty() || tmp.top()!='['){
				score=0;
				break;
			} else {
				if(s[i-1]=='['){
					score += tmpScore;				
				}
				tmpScore/=3;
				tmp.pop();
			}
		}
	}
	if(tmp.empty()) cout << score << endl;
	else cout << 0 << endl;
}
