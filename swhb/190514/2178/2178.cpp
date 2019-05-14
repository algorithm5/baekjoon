#include <iostream>
#include <queue>
using namespace std;
bool box[100][100], visit[100][100];
int x[100], y[100], l[100];
int dx[4] = {1, -1, 0, 0};    //동 서 남 북
int dy[4] = {0, 0, -1, 1};    //동 서 남 북

void enqueue(int px, int py, int pl){
	cout << "enqueue 진입 " << count << endl;
	x[count] = px;
	y[count] = py;
	l[count] = pl;
	count++;
}

void bfs(int px, int py){
	int pos=0;
	enqueue(px,py,1);
	
	while(pos<count && (x[pos]!=c-1 || y[pos] != r-1)){
		cout << "while문 진입" << endl; 
		box[x[pos]][y[pos]] = false;
		
		if (y[pos] > 0 && (box[y[pos] - 1][x[pos]] == true)) {
			enqueue(x[pos], y[pos] - 1, l[pos] + 1); 
			cout << "위쪽으로 한칸 이동, 좌표 = " << (pos-1) << ":" << pos << endl;
		}
		if ((y[pos] < r - 1) && (box[y[pos] + 1][x[pos]] == true)) {
			enqueue(x[pos], y[pos] + 1, l[pos] + 1); 
			cout << "아래쪽으로 한칸 이동, 좌표 = " << (pos+1) << ":" << pos << endl;

		}
		if (x[pos] > 0 && box[y[pos]][x[pos] - 1] == true) {
			enqueue(x[pos] - 1, y[pos], l[pos] + 1); 
			cout << "왼쪽으로 한칸 이동, 좌표 = " << pos << ":" << (pos-1) << endl;

		}
		if (x[pos] < c - 1 && box[y[pos]][x[pos] + 1] == true) {
			enqueue(x[pos] + 1, y[pos], l[pos] + 1); 
			cout << "오른쪽으로 한칸 이동, 좌표 = " << pos << ":" << (pos+1) << endl;

		}
		
		pos++;
	}
	
	if(pos<count) {
		cout << l[pos] << endl;
	}
}
int main(void){
	int r,c;
	cin>>r>>c;
	
//	min = r * c;
	// 입력받은 값을 토대로 초기화하는 과정, O(nm)이지만 n과 m의 최대값은 100, 
	// 최대 10000번의 초기화를 진행한다. 
	// 이렇게 하는 이유는 각 좌표값들이 " " 표시 없이 붙어서 입력되기 때문 
	
	for(int i=0; i<r; i++){
		int tmp;
		cin>>tmp;
		count = c-1;
		while((tmp/10)>=0 && count>=0){
			if((tmp%10)==1){
				box[i][count]=true;
			} else {
				box[i][count]=false;
			}
			tmp /= 10;
			count--;
		}
	}
	
	cout << endl;
	
	for(int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << box[i][j] << " ";
		}
		cout << endl;
	}
	count =0; 
	bfs(0,0);
}
