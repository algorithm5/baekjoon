#include<iostream>

using namespace std;
int map[100][100];
int map2[100][100];

int N, L;

bool isRightRoad(int *);

int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			int n;
			cin >> n;
			map[i][j] = map2[j][i] = n;
		}

	int ans = 0;

	for (int i = 0; i < N; ++i)
	{
		if (isRightRoad(map[i]))
			ans++;

		if (isRightRoad(map2[i]))
			ans++;
	}

	cout << ans;
}
bool isRightRoad(int *val)
{
	int temp[100] = { 0 };

	for (int i = 1; i < N; ++i)
	{
		if (val[i - 1] < val[i])
		{
			if (i - L < 0)
				return false;

			int height = val[i] - 1;

			for (int j = i - 1; j >= i - L; --j)
				if (height != val[j] || temp[j])
					return false;
			for (int j = i - 1; j >= i - L; --j)
				temp[j] = 1;
		}
		else if (val[i - 1] > val[i])
		{
			if (i + L - 1 >= N)
				return false;

			int height = val[i - 1] - 1;

			for (int j = i; j < i + L; ++j)
				if (height != val[j] || temp[j])
					return false;

			for (int j = i; j < i + L; ++j)
				temp[j] = 1;

		}
	}
	return true;
}
