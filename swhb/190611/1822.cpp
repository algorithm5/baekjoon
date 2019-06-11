#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> a;
int count = 0;

bool desc(int a, int b){
	return a>b;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int na, nb;
	cin>> na >> nb;
	long long num;
	for(int i=0; i<na; i++){
		cin>>num;
		a.push_back(num);
	}
	sort(a.begin(), a.end(),desc);

	for(int i=0; i<nb; i++){
		cin>>num;
		
		vector<long long>::iterator it;
		it = find(a.begin(),a.end(),num);
		if(it!=a.end()){
			a.erase(it);
		}
	}
	cout <<a.size() << endl;
	int size = a.size();
	for(int i=0; i<size; i++){
		cout << a.back() << " ";
		a.pop_back();
	}
}
