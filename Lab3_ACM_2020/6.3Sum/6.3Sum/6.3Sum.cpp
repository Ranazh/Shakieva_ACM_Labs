#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.size() < 3)
			return ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		set<vector<int>> sums;
		for (int i = 0; i < n; i++)
		{
			int j = i + 1, k = n - 1;
			while (j < k)
			{
				if (nums[j] + nums[k] + nums[i] == 0)
				{
					sums.insert(vector<int>{nums[i], nums[j], nums[k]});
					j++;
					k--;
				}
				else if (nums[i] + nums[j] + nums[k] < 0)
					j++;
				else k--;
			}
		}
		ans.assign(sums.begin(), sums.end());
		return ans;

	}
};

int main()
{
	vector <int> nums = { -1,0,1,2,-1,-4 };
	Solution *obj = new Solution();
	vector<vector<int>> ans = obj->threeSum(nums);

	for (auto x : ans) {
		cout << "[ ";
		for (auto n : x) {
			cout << n << " ";
		}
		cout << "], ";
	}
	return 0;
}
