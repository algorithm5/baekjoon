#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;

	cin >> N;

	cin >> M;

	vector<string> v;
	vector<string> result;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		string str;
		
		cin >> str;

		auto find = binary_search(v.begin(), v.end(), str);

		if(find)
			result.push_back(str);

	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';

	for (int i = 0; i < result.size();i++) {
		cout << result[i] << '\n';
	}
}