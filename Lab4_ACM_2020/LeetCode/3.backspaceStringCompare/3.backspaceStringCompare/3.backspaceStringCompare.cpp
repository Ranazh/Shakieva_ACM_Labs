#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> a, b;
		string s1 = "";
		string s2 = "";

		for (auto x : S) {
			if (x == '#' && !a.empty()) {
				a.pop();
			}
			else if (x != '#') {
				a.push(x);
			}
		}

		for (auto x : T) {
			if (x == '#' && !b.empty()) {
				b.pop();
			}
			else if (x != '#') {
				b.push(x);
			}
		}
		if (a.size() != b.size()) return false;
		else {
			while (!a.empty()) {
				s1 += a.top();
				s2 += b.top();
				a.pop();
				b.pop();
			}
		}
		return (s1 == s2);
	}
};

int main()
{
	Solution* obj = new Solution();
	string S = "ab#c", T = "ad#c";

	cout << obj->backspaceCompare(S, T);
	return 0;
}
