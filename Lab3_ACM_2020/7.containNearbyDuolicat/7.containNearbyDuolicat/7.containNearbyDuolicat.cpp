#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map <int, int> indCheck;

		for (int i = 0; i < nums.size(); ++i) {
			if (indCheck.count(nums[i]) == 1) {
				if (i - indCheck[nums[i]] <= k) return true;
			}
			indCheck[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	vector <int> nums = { 1,0,1,1 };
	int k = 3;
	Solution *obj = new Solution();
	cout << obj->containsNearbyDuplicate(nums, k);

	return 0;
}
