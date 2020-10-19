#include <iostream>
#include <vector>

using namespace std;
class NumArray {
private: int prefix[10000];//vector for prefix sum
public:
	NumArray(vector<int>& nums) {
		if (nums.size() == 0)
			return;
		//calculating the prefix sum in each point
		prefix[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			prefix[i] = prefix[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return prefix[j];
		return prefix[j] - prefix[i - 1];//the less sum is subtracted from the larger
	}
};
int main() {

	vector<int> nums = { -2, 0,3, -5, 2, -1 };//example
	NumArray* obj = new NumArray(nums);
	cout << obj->sumRange(1, 3);
	return 0;
}

