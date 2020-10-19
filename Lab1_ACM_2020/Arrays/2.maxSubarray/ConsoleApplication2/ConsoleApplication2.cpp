// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class NumArray {
private: int sum = 0, maxSum = 0;
public:
	int maxSubArray(vector<int>& nums) {
		sum = 0;
		maxSum = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];// adding next element
			maxSum = max(sum, maxSum);//compare sum with the previous sum
			sum = max(sum, 0);//is sum became negative start since new point (0)
		}
		return maxSum;
	}
};

int main() {
	vector<int> nums = { -2, 0,3, -5, 2, -1 };
	NumArray* obj = new NumArray();
	cout << obj->maxSubArray(nums);
	return 0;
}
