#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool cmp(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main() {
	int n;

	vector<string> v;
	set<string> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		v.push_back(*it);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

}