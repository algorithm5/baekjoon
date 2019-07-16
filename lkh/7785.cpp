#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> v;
	set<string> s;

	for (int i = 0; i < n; i++) {
		string name, state;
		cin >> name;
		cin >> state;

		if (state == "enter")
			s.insert(name);
		else 
			s.erase(name);
	}

	for (auto it = s.begin(); it != s.end(); it++)
		v.push_back(*it);
	
	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;
}