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

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int m,n;
	cin>>m>>n;
	for(int i=m; i<=n; i++){
		if(i!=1){
			if(i==2){
				cout<<i<<endl;
			} else {
				if(i%2!=0){
					bool selection=true;
					for(int j=2; j<=sqrt(i); j++){
						if(i%j==0){
							selection=false;
							break;
						}
					}
					if(selection) cout<<i<<endl;
				}
				
			}
		
		}
	}
	return 0;
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
