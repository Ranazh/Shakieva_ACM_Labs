#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool isOperator(string s)
	{
		if (s == "-" || s == "+" || s == "*" || s == "/")
			return 1;
		return 0;
	}

	int Calculate(int a, int b, string x) {
		if (x == "+") {
			return a + b;
		}
		else if (x == "-") {
			return b - a;
		}
		else if (x == "*") {
			return a * b;
		}
		else return b / a;
	}
	int evalRPN(vector<string>& tokens) {
		stack <string>nums;
		int ans = 0;
		for (auto x : tokens) {
			if (isOperator(x)) {
				int a = stoi(nums.top());
				nums.pop();
				int b = stoi(nums.top());
				nums.pop();
				ans = Calculate(a, b, x);
				nums.push(to_string(ans));
			}
			else {
				nums.push(x);
			}
		}
		return stoi(nums.top());
	}
};
int main()
{
	vector<string> op = { "2", "1", "+", "3", "*" };
	Solution* obj = new Solution();

	cout << obj->evalRPN(op);
}
