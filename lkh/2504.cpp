#include<iostream>
#include<stack>
#include<cstring>
#include<string>

using namespace std;

int main()
{
	char str[31];
	stack<char> s;

	int val = 1;
	int sum = 0;

	bool wrong = false;

	cin >> str;

	for (int i = 0; i < str[i]; i++) {

		switch (str[i]) {
		case '(':

			val *= 2;
			s.push('(');

			break;
		case '[':

			val *= 3;
			s.push('[');

			break;

		case ')':

			if (str[i - 1] == '(')
				sum += val;

			if (s.empty()) {
				cout << 0;
				return 0;
			}

			if (s.top() == '(')
				s.pop();

			val /= 2;

			break;

		case ']':

			if (str[i - 1] == '[')
				sum += val;

			if (s.empty()) {
				cout << 0;
				return 0;
			}

			if (s.top() == '[')
				s.pop();

			val /= 3;

			break;
		}
	}

	if (!s.empty()) {
		cout << 0;
		return 0;
	}

	cout << sum;
}