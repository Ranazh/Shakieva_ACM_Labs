#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MissingNumber {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i)
				return i;
		}
		return nums.size();
	}
};
int main() {

	vector<int> nums = { 0, 1, 2, 4, 5 };
	MissingNumber* obj = new MissingNumber();
	cout << obj->missingNumber(nums);
	return 0;
}
