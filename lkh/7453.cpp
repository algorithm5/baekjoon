#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int size = 0;

	cin >> size;

	int *arr = new int[size];
	int *arr2 = new int[size];
	int *arr3 = new int[size];
	int *arr4 = new int[size];

	for (int i = 0; i < size; i++) 
	{
		cin >> arr[i];
		cin >> arr2[i];
		cin >> arr3[i];
		cin >> arr4[i];
	}

	int *sum_arr = new int[size * size];
	int *sum_arr2 = new int[size * size];

	int cnt = 0;

	for (int i= 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			sum_arr[cnt] = arr[i] + arr2[j];
			sum_arr2[cnt] = arr3[i] + arr4[j];
			cnt++;
		}
	}

	delete arr;
	delete arr2;
	delete arr3;
	delete arr4;

	sort(sum_arr, sum_arr + size * size);
	sort(sum_arr2, sum_arr2 + size * size);

	long cnt_val = 0;

	for (int i = 0; i < size * size; i++) 
	{
		int lower_val = lower_bound(sum_arr, sum_arr + size * size, sum_arr2[i] * -1) - sum_arr;
		int upper_val = upper_bound(sum_arr, sum_arr + size * size, sum_arr2[i] * -1) - sum_arr;

		cnt_val += (upper_val - lower_val);
	}

	cout << cnt_val;

	delete sum_arr;
	delete sum_arr2;
}