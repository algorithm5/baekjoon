#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cout << arr[0] << " " << arr[n-1] << "\n";
} 
