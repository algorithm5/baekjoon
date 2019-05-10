/*


*/


#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		stack<char> left, right;
		string input;
		cin>>input;
		if(input.length()>=1 && input.length()<=1000000){
			for(int j=0; j<input.length(); j++ ){
				if(input[j]=='<'){
					if(!(left.empty())){
						right.push(left.top());
						left.pop();
					}
				} else if(input[j]=='>'){
					if(!(right.empty())){
						left.push(right.top());
						right.pop();
					}
				} else if(input[j]=='-'){
					if(!(left.empty())){
						left.pop();
					}		
				} else {
					left.push(input[j]);
				}
			}
			string result="";
			while(!right.empty()){
				left.push(right.top());
				right.pop();
			}
			while(!left.empty()){
				result+=left.top();
				left.pop();
			}
			reverse(result.begin(),result.end());
			cout<<result<<endl;
		}
	}
}

/*

*/
