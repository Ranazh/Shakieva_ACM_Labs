#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	stack <char> openBr;
	for (auto ch:s) {
		switch (ch) {
		case '}': {
			if (openBr.empty() || openBr.top() != '{') {
				cout << "no";
				return 0;
			}
			openBr.pop();
		}break;
		case ']': {
			if (openBr.empty() || openBr.top() != '[') {
				cout << "no";
				return 0;
			}
			openBr.pop();
		}break;
		case ')': {
			if (openBr.empty() || openBr.top() != '(') {
				cout << "no";
				return 0;
			}
			openBr.pop();
		}break;
		default:
			openBr.push(ch);
		}
	}
	if (openBr.empty()) {
		cout << "yes";
	}
	else {
		cout << "no";
	}

	return 0;

}

