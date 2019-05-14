#include <iostream>
#include <queue>
using namespace std;
int r,c;
bool box[100][100], visit[100][100];
int x[100], y[100], l[100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int px, int py){
	queue<pair<pair<int, int>, int > > q;
    q.push(make_pair(make_pair(0,0),1));    //첫째pair 위치, 둘째pair 움직인거리
    visit[0][0] = 1;
	
    while(!q.empty()) {
        
        int x = q.front().first.second;
        int y = q.front().first.first;
        int z = q.front().second;
        
        q.pop();
 
        if(x == c-1 && y == r-1)
            return z;
 
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if(nx < 0 || ny < 0 || nx >= c || ny >= r)
                continue;
            if(visit[ny][nx] == 1)
                continue;
            if(box[ny][nx] != 1)
                continue;
            
            q.push(make_pair(make_pair(ny,nx),z+1));
            visit[ny][nx] = 1;
        }
    }
}
 
int main(void){
	
	cin>>r>>c;
	
//	min = r * c;
	// 입력받은 값을 토대로 초기화하는 과정, O(nm)이지만 n과 m의 최대값은 100, 
	// 최대 10000번의 초기화를 진행한다. 
	// 이렇게 하는 이유는 각 좌표값들이 " " 표시 없이 붙어서 입력되기 때문 
	int count;
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
	
	
	count =0; 
	cout << bfs(0,0) << endl;
}
