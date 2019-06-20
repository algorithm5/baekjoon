#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef struct{
	int x;
	int y;
}Pos;
int size;
Pos source;			// Source pos
Pos target;			// Destination pos

int bfs(){
	queue<Pos> q;
	q.push(source);
	
	set<Pos> checked;
	checked.insert(source);
	if(source.x==target.x && source.y==target.y){
		return 0;
	}
	int count = 0;
	while(!q.empty()){
		// (-2,-1),(-2,1),(-1,-2),(-1,2),(1,-2),(1,2),(2,-1),(2,1) 
		if(q.front().x==target.x && q.front().y==target.y){
			return count;
		}else {
			if(q.front().x-2>=0 && q.front().y-1>=0){
				Pos tmp;
				tmp.x = q.front().x-2;
				tmp.y = q.front().y-1;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
				
			}
			if(q.front().x-2>=0 && q.front().y+1<size){
				Pos tmp;
				tmp.x = q.front().x-2;
				tmp.y = q.front().y+1;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
			if(q.front().x-1>=0 && q.front().y-2>=0){
				Pos tmp;
				tmp.x = q.front().x-1;
				tmp.y = q.front().y-2;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
			if(q.front().x-1>=0 && q.front().y+2<size){
				Pos tmp;
				tmp.x = q.front().x-1;
				tmp.y = q.front().y+2;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
			if(q.front().x+1<size && q.front().y-2>=0){
				Pos tmp;
				tmp.x = q.front().x+1;
				tmp.y = q.front().y-2;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
			if(q.front().x+1<size && q.front().y+2<size){
				Pos tmp;
				tmp.x = q.front().x+1;
				tmp.y = q.front().y+2;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
			if(q.front().x+2<size && q.front().y-1>=0){
				Pos tmp;
				tmp.x = q.front().x+2;
				tmp.y = q.front().y-1;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
			if(q.front().x+2<size && q.front().y+1<size){
				Pos tmp;
				tmp.x = q.front().x+2;
				tmp.y = q.front().y+1;
				if(checked.count(tmp)==0){
					checked.insert(tmp);
					q.pop();
					q.push(tmp);
				}
			}
		}
		count++;
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
		cin>>target.x>>target.y;
		
		cout<<bfs()<<endl;
//		cout<<"SIZE = " << size << ", Source = " << x << "," << y << ", Dest = " << tx << ty << endl;
	}
}
