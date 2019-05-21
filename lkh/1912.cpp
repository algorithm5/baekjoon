#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int size;
	cin >> size;

	int* arr = new int[size];
	int* arr_sum = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	arr_sum[0] = arr[0];

	int max = arr[0];

	for (int i = 0; i < size; i++) 
	{
		int j = i + 1;

		if (j < size) 
		{
			if (arr_sum[j - 1] + arr[j] > arr[j])
				arr_sum[j] = arr_sum[j - 1] + arr[j];
			else
				arr_sum[j] = arr[j];

			if (arr_sum[j] >= max)
				max = arr_sum[j];
		}
	}

	cout << max;

	delete arr;
	delete arr_sum;

	return 0;
}
