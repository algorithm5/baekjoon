#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int a;
	int b;
	set<int> s;

	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;

		auto it = s.find(num);

		if (it != s.end())
			s.erase(it);
	}

	cout << s.size() << '\n';

	for (auto num : s)
		cout << num << " ";

}