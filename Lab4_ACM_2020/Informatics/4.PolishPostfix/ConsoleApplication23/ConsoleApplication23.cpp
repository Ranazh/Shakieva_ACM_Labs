#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperate(char c) {
	if (c == '-' || c == '+' || c == '*')
		return 1;
	return 0;
}

bool isDigit(char c) {
	return c >= '0' && '9' >= c;
}
int calculate(int a, int b, char c) {
	switch (c) {
	case '+':return a + b;
	case '-':return b - a;
	case '*': return a * b;
	}
	return 0;
}
int main()
{
	string s;
	int ans = 0, n = 0;
	stack <int> nums;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c == ' ' && isDigit(s[i-1])) {
			nums.push(n);
			n = 0;
		}
		if (isOperate(c)) {
			int a = nums.top();
			nums.pop();
			int b = nums.top();
			nums.pop();
			ans = calculate(a, b, c);
			nums.push(ans);
		}
		else if(isDigit(c)) {
			n = n * 10 + (c - '0');
		}
	}
	cout << ans;
	return 0;
}