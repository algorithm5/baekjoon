#include <iostream>
using namespace std;

/*
L미터의 롤 케이크 : L개의 원소를 가지는 배열
N명 : 방청자의 수(반복문의 조건)
가장 왼쪽 조각 : 1번, 가장 마지막 조각 : L번
P,K 숫자 : P번 열부터 K번 열까지를 원함 
*/

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int l;
	cin>>l;
	
	int arr[l] = {0, };
	
	int n;
	cin>>n;
	int max=-1; int iter = -1;
	
	
	for(int i=0; i<n; i++){
		int p,k;
		cin>>p>>k;
		int tmp = k-p;
		if(tmp>max){
			max=tmp;
			iter=i+1;

		}
		for(int j=p-1; j<k; j++){
			if(arr[j]==0){
				arr[j] = i+1;
			}
		}
	} 
	
	cout << iter << "\n";
	int res[n]={0, };
	
	for(int i=0; i<l; i++){
		int tmp = arr[i]-1;
		res[tmp]++;
	}
	
	int max2=-1; int iter2 = -1;
	for(int i=0; i<n; i++){
		if(res[i]>max2){
			max2=res[i];
			iter2 = i+1;
		}
	}
	cout << iter2 << "\n";
}
