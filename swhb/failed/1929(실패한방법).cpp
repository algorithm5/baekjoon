/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초		256 MB		36668	10294	7168		28.354%

문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
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
예제 입력 1 
3 16

예제 출력 1 
3
5
7
11
13

*/
