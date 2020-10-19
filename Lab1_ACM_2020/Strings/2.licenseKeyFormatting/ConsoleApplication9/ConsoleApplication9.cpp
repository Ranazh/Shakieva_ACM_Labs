#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string str, int K) {
		int n = str.size();
		for (int i = 0; i < n; i++) {//Upper all char in the string
			str[i] = toupper(str[i]);
		}
		int temp = K + 1; //variable to checking the group length
		string result = "";

		// skip original '-' while keep tracking t to add '-'
		for (int i = n - 1; i >= 0; i--) {//all groups expect the first must have K elements, so we start collect it fron the end
			if (str[i] != '-') {
				temp--;
				if (temp == 0) {//the group is collecting
					result += "-";
					temp = K;
				}
				result += str[i];
			}
		}
		reverse(result.begin(), result.end());//reversing the collecting string
		return result;
	}
};
int main() {
	string s;
	int k;
	cin >> s >> k;
	Solution* obj = new Solution();
	cout << obj->licenseKeyFormatting(s, k);
	return 0;
}
