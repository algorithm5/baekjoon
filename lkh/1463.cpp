#include <iostream>
#include <queue>

using namespace std;

struct Obj
{
	int num;
	int operation_cnt;
};

int main(void)
{
	int input;

	cin >> input;

	queue<Obj> q;

	q.push({ input, 0});

	while (!q.empty())
	{
		int num = q.front().num;
		int operation_cnt = q.front().operation_cnt;

		if (num == 1) {
			cout << operation_cnt;
			break;
		}

		q.pop();

		q.push({num-1, operation_cnt+1});

		if (num % 2 == 0)
			q.push({ num / 2, operation_cnt + 1 });

		if (num % 3 == 0)
			q.push({ num / 3, operation_cnt + 1 });
	}
	
	return 0;
}