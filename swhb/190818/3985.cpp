#include <iostream>
using namespace std;

/*
L������ �� ����ũ : L���� ���Ҹ� ������ �迭
N�� : ��û���� ��(�ݺ����� ����)
���� ���� ���� : 1��, ���� ������ ���� : L��
P,K ���� : P�� ������ K�� �������� ���� 
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
