#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int number;
	int count;
}Point;

int main(void){
	int n;
	cin>>n;
	queue<Point> qu;
	Point point;
	point.number=n;
	point.count=0;
	qu.push(point);
	while(!qu.empty()){
		int target = qu.front().number;
		int count = qu.front().count;
		qu.pop();
		if(target%3==0) {
			Point tmpPoint;
			tmpPoint.number = target/3;
			tmpPoint.count = count+1;
			qu.push(tmpPoint);
		}
		if(target%2==0) {
			Point tmpPoint;
			tmpPoint.number = target/2;
			tmpPoint.count = count+1;
			qu.push(tmpPoint);
		}
		if(target==1){
			cout<<count<<endl;
			break;
		}
		if(target!=1){
			Point tmpPoint;
			tmpPoint.number = target-1;
			tmpPoint.count = count+1;
			qu.push(tmpPoint);
		}
	}
}
