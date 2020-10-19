#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string s) {

		unordered_map<char, string> checkMap1;
		unordered_map<string, char> checkMap2;

		string temp;
		char symb;
		int j = 0;

		if (pattern.empty() || s.empty()) return false;
		for (int i = 0; i <= s.size(); i++) {
			if (s[i] == ' ' || i == s.size()) {
				symb = pattern[j];

				if (checkMap1.count(symb) && checkMap1[symb] != temp || checkMap2.count(temp) && checkMap2[temp] != symb) {
					return false;
				}
				checkMap1[symb] = temp;
				checkMap2[temp] = symb;
				temp = "";
				j++;
			}
			else {
				temp += s[i];
			}
		}
		if (j != pattern.size()) {
			return false;
		}
		return true;
	}
};


int main()
{
	string pattern = "abba", s = "dog cat cat dog";
	Solution *obj = new Solution();
	cout << obj->wordPattern(pattern, s);

	return 0;
}
