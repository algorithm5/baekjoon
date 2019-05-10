/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초		128 MB		10750	4070	3288		38.861%
문제
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 
지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이
a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. 
(이 위치는 가장 처음 큐에서의 위치이다.) 
이때, 그 원소를 주어진 순서대로 뽑아내는데 
드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다.
N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 
둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다.
위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.
*/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(void){
	int capa = 0;
	int n = 0;
	deque<int> dq;
	
	int result = 0;
	
	// 큐의 크기와 입력 값의 개수를 받아온다. 
	cin>>capa>>n;
	
	// 큐 초기화 
	for(int i=capa; i>0; i--){
		dq.push_front(i);
	}
	for(int i=0; i<n; i++){
		int target=0;
		cin>>target;
		
		int pointer=1;
		for(deque<int>::iterator iter = dq.begin(); iter<dq.end(); iter++){
			if(*iter==target)break;
			pointer++;
		}
		
		int left = pointer-1;
		int right=dq.size()-pointer+1;
		
		if(left<right){
			for(int j=1; j<=left; j++){
				int val = dq.front();
				dq.pop_front();
				dq.push_back(val);
				result++;
			}
			dq.pop_front();
		} else {
			for(int j=1; j<=right; j++){
				int val = dq.back();
				dq.pop_back();
				dq.push_front(val);
				result++;
			}
			dq.pop_front();
		}
	}
	cout<<result<<endl;
}
/*
예제 입력 1 
10 3
1 2 3

예제 출력 1 
0

예제 입력 2 
10 3
2 9 5

예제 출력 2 
8

예제 입력 3 
32 6
27 16 30 11 6 23

예제 출력 3 
59

예제 입력 4 
10 10
1 6 3 2 7 9 8 4 10 5

예제 출력 4 
14
*/
