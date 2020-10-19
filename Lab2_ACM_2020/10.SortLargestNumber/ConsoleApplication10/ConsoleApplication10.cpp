#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	string x = to_string(a);
	string y = to_string(b);
	return ((x + y) > (y + x));
}
class Solution {
public:

	string largestNumber(vector<int>& vec) {
		int n = vec.size();
		if (n == 0) return "";
		sort(vec.begin(), vec.end(), compare);
		int count = 0;
		string ans;
		for (int i = 0; i < n; i++) {
			if (vec[i] == 0) count++;
			ans += to_string(vec[i]);

		}
		if (vec.size() == count) return ans = "0";
		else return ans;
	}
};

int main()
{
	Solution *obj = new Solution();
	vector<int> v = { 3,30,34,5,9 };
	cout << obj->largestNumber(v);
	return 0;
}
