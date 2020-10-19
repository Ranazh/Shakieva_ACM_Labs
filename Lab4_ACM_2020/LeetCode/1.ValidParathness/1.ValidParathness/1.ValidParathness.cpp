#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {

		stack<char> check;
		char temp = 0;

		for (auto c : s) {
			switch (c) {
			case '[':
				check.push(c);
				break;
			case '{':
				check.push(c);
				break;
			case '(':
				check.push(c);
				break;
			case '}':
				if (!check.empty()) {
					temp = check.top();
					check.pop();
				}
				if (temp != '{') return false;
				temp = 0;
				break;
			case ']':
				if (!check.empty()) {
					temp = check.top();
					check.pop();
				}
				if (temp != '[') return false;
				temp = 0;
				break;
			case ')':
				if (!check.empty()) {
					temp = check.top();
					check.pop();
				}
				if (temp != '(') return false;
				temp = 0;
				break;
			default: return false;
			}

		}

		return (check.empty());

	}
};

int main()
{
	string s;
	cin >> s;
	Solution *obj = new Solution();
	cout << obj->isValid(s);

	return 0;
}