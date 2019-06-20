#include <iostream>
#include <queue>
using namespace std;
typedef struct{
	int x;
	int y;
	int count;
}Pos;
int size;
Pos source;			// Source pos
Pos target;			// Destination pos

int bfs(){
	queue<Pos> q;
	q.push(source);
	if(source.x==target.x && source.y==target.y){
		return 0;
	}
	
	while(!q.empty()){
		// (-2,-1),(-2,1),(-1,-2),(-1,2),(1,-2),(1,2),(2,-1),(2,1) 
		if(q.front().x==target.x && q.front().y==target.y){
			return q.front().count;
		}else {
			if(q.front().x-2>=0 && q.front().y-1>=0){
				Pos tmp;
				tmp.x = q.front().x-2;
				tmp.y = q.front().y-1;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x-2>=0 && q.front().y+1<size){
				Pos tmp;
				tmp.x = q.front().x-2;
				tmp.y = q.front().y+1;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x-1>=0 && q.front().y-2>=0){
				Pos tmp;
				tmp.x = q.front().x-1;
				tmp.y = q.front().y-2;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x-1>=0 && q.front().y+2<size){
				Pos tmp;
				tmp.x = q.front().x-1;
				tmp.y = q.front().y+2;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x+1<size && q.front().y-2>=0){
				Pos tmp;
				tmp.x = q.front().x+1;
				tmp.y = q.front().y-2;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x+1<size && q.front().y+2<size){
				Pos tmp;
				tmp.x = q.front().x+1;
				tmp.y = q.front().y+2;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x+2<size && q.front().y-1>=0){
				Pos tmp;
				tmp.x = q.front().x+2;
				tmp.y = q.front().y-1;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
			if(q.front().x+2<size && q.front().y+1<size){
				Pos tmp;
				tmp.x = q.front().x+2;
				tmp.y = q.front().y+1;
				tmp.count = q.front().count+1;
				q.pop();
				q.push(tmp);
			}
		}
	}
}
	
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>size;
		cin>>source.x>>source.y;
		source.count = 0;
		cin>>target.x>>target.y;
		
		cout<<bfs()<<endl;
//		cout<<"SIZE = " << size << ", Source = " << x << "," << y << ", Dest = " << tx << ty << endl;
	}
}