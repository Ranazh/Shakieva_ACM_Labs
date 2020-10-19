#include <iostream>
#include <vector>

using namespace std;

class ProductVector{
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int product = 1;
		for (int i = 0; i < nums.size(); i++) {
			product *= nums[i];
		}
		vector<int> output(nums.size(), 1);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0)
				output[i] = product / nums[i];
		}
		return output;
	}
};
int main() {

	vector<int> nums = { 1, 2, 3, 4 };
	ProductVector* obj = new ProductVector();
	vector<int> ans(nums.size(), 1);
	ans = obj->productExceptSelf(nums);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
