/*
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��		256 MB		36668	10294	7168		28.354%

����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000)

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void){

	int m,n;
	scanf("%d %d", &m, &n);
	bool * arr = new bool[n+1];
	
	for(int i=0; i<n+1; i++){
		arr[i] = true;	
	}
	
	int j;
	
	for(int i=2; i<n+1; i++){
		if((unsigned int)pow(i,2)>1000001){
			break;
		} else {
			for(j=(int)pow(i,2); j<n+1;){
				arr[j]=false;
				j=j+i;
			}
		}
	} 
	
	if(m==1)m++;
	
	for(int i=m; i<n+1; i++){
		if(arr[i]&&i>=m){
			printf("%d\n", i);
		}
	}
	
	delete []arr;
}

/*
���� �Է� 1 
3 16

���� ��� 1 
3
5
7
11
13

*/
