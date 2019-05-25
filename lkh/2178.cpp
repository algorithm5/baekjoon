#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>

using namespace std;

struct Space {
	int x;
	int y;
	int move;
};

int main()
{
	int spaces[101][101];
	bool visited[101][101] = { false };

	int current_x = 0;
	int current_y = 0;
	int current_move = 0;

	int n;
	int m;

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &spaces[i][j]);
		}
	}

	int x_direction[4] = { -1, 1, 0, 0 };
	int y_direction[4] = { 0, 0, -1, 1 };

	queue<Space> q;

	q.push({ current_x , current_y, current_move });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int move = q.front().move;

		if (x == n - 1 && y == m - 1) {
			cout << move + 1;
			return 0;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {

			bool isRightRoot
				= y + y_direction[i] >= 0 && x + x_direction[i] >= 0
				&& y + y_direction[i] <= m - 1 && x + x_direction[i] <= n - 1;

			if (!isRightRoot)
				continue;

			if (spaces[x + x_direction[i]][y + y_direction[i]] == 1
				&& !visited[x + x_direction[i]][y + y_direction[i]]) {

				if (x + x_direction[i] == n && y + y_direction[i] == m) {
					cout << move + 1;
					return 0;
				}

				visited[x + x_direction[i]][y + y_direction[i]] = true;

				q.push({ x + x_direction[i], y + y_direction[i], move + 1 });
			}
		}
	}

}