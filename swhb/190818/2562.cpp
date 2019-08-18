#include <iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int arr[9];
	int max = -1;
	int iter = -1;
	
	for(int i=0; i<9; i++){
		cin>>arr[i];
		if(arr[i] >= max){
			max=arr[i];
			iter = i;
		}
	}	
	cout<<max << "\n" << iter+1 << "\n";
}
