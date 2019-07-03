#include <iostream>
#define ARRIVED 100000;
using namespace std;

int q[10001];
int head=0,l=0; 

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
		int edge[n+1][n+1] = {0};
	int visited[n+1]={0};
	
	int net;
	cin>> net;

	
	for(int i=0; i<net; i++){
		int a,b;
		cin>>a>>b;
		edge[a][b]=1;
		edge[b][a]=1;
	}

	q[l++]=1;
	
	while(head!=l){
		int tmp = q[head++];
		cout << "head = " << head << ", end = " << l << ", tmp = " << tmp << endl;
		visited[tmp]=1;
		for(int i=1; i<=n; i++){
			if(edge[tmp][i]==1){
				q[l++]=i;
				edge[tmp][i]=ARRIVED;
				edge[i][tmp]=ARRIVED;
			}
		}
	}
	int count=0;
	for(int i=1; i<=n; i++){
		if(visited[i]){
			count++;
		}
	}
	cout << count << '\n';
}
