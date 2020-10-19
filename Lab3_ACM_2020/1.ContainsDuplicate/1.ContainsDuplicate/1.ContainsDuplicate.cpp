#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set <int> check;
		for (int i : nums) {
			if (check.find(i) != check.end())
				return true;
			else
				check.insert(i);
		}
		return false;
	}
};

int main()
{
	Solution* obj = new Solution();
	vector <int> nums = { 1,1,1,3,3,4,3,2,4,2 };

	cout << obj->containsDuplicate(nums);
	return 0;
}
