#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map <string, vector<string>> keyMap;

		for (auto x : strs) {
			string key = x;
			sort(key.begin(), key.end());

			keyMap[key].push_back(x);
		}

		vector<vector<string>> ans;

		for (auto x : keyMap) {
			string key = x.first;
			vector <string> value = x.second;

			ans.push_back(value);
		}

		return ans;
	}

};

int main()
{
	vector<string> words = { "eat","tea","tan","ate","nat","bat" };
	vector<vector<string>> ans;
	Solution *obj = new Solution();
	ans = obj->groupAnagrams(words);
	for (auto x : ans) {
		for (auto y : x) {
			cout << y << ", ";
		}
		cout << endl;
	}

	return 0;
}
