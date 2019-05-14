
/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초		128 MB		7261	2343	1952		37.202%

문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
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
