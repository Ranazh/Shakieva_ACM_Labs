#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map <int, int> chMap;
		int dif;
		for (int i = 0; i < nums.size(); ++i) {
			dif = target - nums[i];

			if (chMap.count(dif))
				return { chMap[dif], i };
			chMap[nums[i]] = i;
		}

		return {};
	}
};

int main()
{
	vector<int> nums = { 2,7,11,15 }, ans;
	int target = 9;
	Solution *obj = new Solution();
	ans = obj->twoSum(nums, 9);
	for (auto x : ans) {
		cout << x << " ";
	}
}
