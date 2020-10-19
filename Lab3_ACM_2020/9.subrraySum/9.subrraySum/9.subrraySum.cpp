#include <iostream>
#include <string>
#include <map>
#include <unordered_map>


using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0)
			return 0;

		unordered_map<int, int> mp;
		int ans = 0, curSum = 0;

		for (int num : nums)
		{
			curSum += num;

			if (curSum == k)
				++ans;

			if (mp.find(curSum - k) != mp.end())
				ans += mp[curSum - k];

			mp[curSum] += 1;
		}

		return ans;
	}
};

int main() {
	vector <int> nums = { 1, 2, 3, 3, 3 };
	int k = 2;
	Solution* obj = new Solution();

	cout << obj->subarraySum(nums, k);
	return 0;
}
	


