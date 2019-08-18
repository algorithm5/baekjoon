#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int arr[8] = {0, };
	
	for(int i=0; i<8; i++){
		cin>>arr[i];
	}
	
	int flow = 0;
	// -1 => des, 0 => mix, 1 => ass;
	for(int i=1; i<8; i++){
		int tmp = arr[i-1]-arr[i];
		if(abs(tmp)==1){
			flow=tmp;
		} else {
			flow = 0;
			break;
		}
	}
	if(flow == 1){
		cout << "descending\n";
	} else if(flow==0){
		cout << "mixed\n";
	} else {
		cout << "ascending\n";
	}
	
}
