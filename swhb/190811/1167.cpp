#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[100001];
vector<pair<int, int>> graph[100001];

int result = 0;
int farthestNode = 0;

void DFS(int dest, int dist){
	if(visited[dest]) return;
	
	visited[dest] = true;
	
	if(result < dist){
		result = dist;
		farthestNode = dest;
	}
	
	for(int i=0; i<graph[dest].size(); i++){
		DFS(graph[dest][i].first, dist+graph[dest][i].second);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		int source;
		cin>>source;
		
		while(true){
			int dest, dist;
			cin>>dest;
			if(dest == -1){
				break;
			}
			cin>>dist;
			graph[source].push_back({dest, dist});
		}
	}
	
	memset(visited, false, sizeof(visited));
	DFS(1,0);
	memset(visited, false, sizeof(visited));
	result = 0;
	
	DFS(farthestNode, 0);
	
	cout << result << "\n";
	
	return 0;
}
