#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {

public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> cnt;
		for (int x : nums) {
			cnt[x]++;
		}

		vector<pair<int, int>> v;

		for (auto x : cnt) {
			v.push_back({ x.second, x.first });
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(v[i].second);
		}

		return ans;
	}
};

int main() {
	int k = 2;
	vector <int> nums = { 1,1,1,2,2,3 };
	Solution* obj = new Solution();

	
	return 0;
}



