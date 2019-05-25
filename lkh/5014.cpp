#include <iostream>
#include <queue>

using namespace std;

struct Obj
{
	int floor;
	int btn_clk_cnt;
};

int main()
{
	int f;
	int s;
	int g;
	int u;
	int d;

	bool isVisited[1000001] = {false};

	cin >> f >> s >> g >> u >> d;
	
	queue<Obj> q;

	q.push({s, 0});

	int cnt = 0;

	while (!q.empty())
	{
		int floor = q.front().floor;
		int btn_clk_cnt = q.front().btn_clk_cnt;

		q.pop();
		
		if (floor == g) {
			cout << btn_clk_cnt;
			return 0;
		}
	
		if (floor + u <= f && !isVisited[floor + u]) {
			q.push({floor + u, btn_clk_cnt + 1});
			isVisited[floor + u] = true;
		}

		if (floor - d > 0 && !isVisited[floor - d]) {
			q.push({floor - d, btn_clk_cnt + 1});
			isVisited[floor - d] = true;
		}
	}

	cout << "use the stairs";
}