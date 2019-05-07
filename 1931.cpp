#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Conference
{
	int startTime;
	int endTime;
};

int time;

bool cmp(Conference c, Conference c_);

int main() {

	int size;
	cin >> size;

	Conference *arr = new Conference[size];

	for (int i = 0; i < size; i++)
	{
		Conference c;
		cin >> c.startTime;
		cin >> c.endTime;
		arr[i] = c;
	}

	sort(arr, arr + size, cmp);

	int time = 0;
	int temp = 0;

	for (int i = 0; i < size; i++) 
	{
		if (temp <= arr[i].startTime) 
		{
			temp = arr[i].endTime;
			time++;
		}
	}

	cout << time;

	delete arr;

	return 0;
}

bool cmp(Conference c, Conference c_)
{
	if (c.endTime == c_.endTime)
		return c.startTime < c_.startTime;
	else
		return c.endTime < c_.endTime;
}