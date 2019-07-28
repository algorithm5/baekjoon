#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr[101];
bool visited[101];

int ans = 0;

void dfs(int x) {

	visited[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		int next = arr[x][i];

		if (!visited[next]) {
			ans++;
			dfs(next);
		}
	}
}

int main() {

	cin.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y; 
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	dfs(1);

	cout << ans << '\n';
	return 0;
}