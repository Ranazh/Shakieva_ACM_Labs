#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string sortString(string s) {
		string ans = "";
		sort(s.begin(), s.end());
		bool flag;

		while (!s.empty()) {//increasing
			if (s.size() > 0) {
				ans.push_back(s[0]);
				s.erase(0, 1);
			}

			while (true) {
				flag = false;
				for (int i = 0; i < s.size(); i++) {
					if (ans.back() < s[i]) {
						ans.push_back(s[i]);
						flag = true;
						s.erase(i, 1);
						break;
					}
				}
				if (!flag)
					break;
			}

			if (s.size() > 0) {
				ans.push_back(s[s.size() - 1]);
				s.pop_back();
			}

			while (true) {//decreasing
				flag = false;
				for (int i = s.size() - 1; i >= 0; i--) {
					if (ans.back() > s[i]) {
						ans.push_back(s[i]);
						flag = true;
						s.erase(i, 1);
						break;
					}
				}
				if (!flag)
					break;
			}
		}

		return ans;
	}
};
int main()
{
	Solution *obj = new Solution();
	string s;
	cin >> s;
	cout << obj->sortString(s);

	return 0;
}
