#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	set<string> listSet;
	
	string name;
	string type;
	for(int i=0; i<n; i++){
		cin>>name>>type;
		if(type=="enter"){
			listSet.insert(name);
		} else {
			listSet.erase(name);
		}
	}
	
	for (auto it = listSet.rbegin(); it != listSet.rend(); it++){
      cout << *it << "\n";
  }
}
