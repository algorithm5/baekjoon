#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b)) 
const int MAX = 100001;
 
struct pos {
    int node;
    int weight;
};
 
vector<pos> relations[MAX];
bool c[MAX];
int dist[MAX];

int length;
int max_index;

void search(queue<pos> &q){
	length = 0;
	max_index = 0;
	
	while (!q.empty()) {
		int node = q.front().node;
		q.pop();
		
		for (int i = 0; i<relations[node].size(); i++) {
			int next = relations[node][i].node;
			int distance = relations[node][i].weight;
			if (c[next] == false) {
				c[next] = true;
				dist[next] = dist[node] + distance;
				if (dist[next] > length || length == 0) {
					length = dist[next];
					max_index = next;
				}
				q.push(pos{ next,0 });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	
	for (int i = 1; i <= n; i++) {
		int start;
		
		scanf("%d", &start);
		while (1) {
			int node, weight;
			cin>>node;
			if (node == -1) break;
			cin>>weight;
			relations[start].push_back(pos{ node,weight });
		}
	}
	
	queue<pos> q;
	
	q.push(pos{ 1,0 });
	c[1] = true;
	
	search(q);
	
	for (int i = 0; i <= n; i++) {
		dist[i] = 0;
		c[i] = false;
	}
	
	q.push(pos{ max_index,0 });
	c[max_index] = true;
	
	search(q);
 
    cout << length << "\n";
}
