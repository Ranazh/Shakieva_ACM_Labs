#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxAverage {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double sum = 0, j = 0, max_average = INT_MIN;
		if (nums.size() < k) {
			for (int i = 0; i < nums.size(); i++)
				sum += nums[i];
			max_average = sum / nums.size();
		}
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (i >= k - 1) {
				double avg = sum / k;
				max_average = max(max_average, avg);
				sum -= nums[j];
				j++;
			}
		}
		return max_average;
	}
};

int main() {
	vector<int> nums = { 1, 12, -5, -6, 50, 3 };
	maxAverage* obj = new maxAverage();
	cout << obj->findMaxAverage(nums, 4);

}
