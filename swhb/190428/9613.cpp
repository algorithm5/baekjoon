
/*
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��		128 MB		7261	2343	1952		37.202%

����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

int gcd(int a, int b){
	if(a<b) swap(a,b);
	while(b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}

int main(){
	int t;
	cin>>t;
	
	if(t<=100){
		for(int i=0; i<t; i++){
			int values[100];
			int n;
			cin>>n;
			if(n<=100){
			
				for(int j=0;j<n; j++){
					cin>>values[j];
				}
				long result = 0;
				for(int k=0; k<n; k++){
					for(int l=k+1;l<n; l++){
						result += gcd(values[k],values[l]);
					}
				}
				
				cout << result << endl;
			}
		}
	}
	
	return 0;
}
/*
3
4 10 20 30 40
3 7 5 12
3 125 15 25

70
3
35
*/
