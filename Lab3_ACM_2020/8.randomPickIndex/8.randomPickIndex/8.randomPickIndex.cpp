#include <iostream>
#include <string>
#include <map>
#include <unordered_map>


using namespace std;
//not solved
class Solution {
public:
	unordered_map<int, vector<int>> numsMap;

	Solution(vector<int>& nums) {

		for (int i = 0; i < nums.size(); ++i)
		{
			numsMap[nums[i]].push_back(i);
		}
	}

	int pick(int target) {

		if (!numsMap.count(target))
		{
			return -1;
		}

		vector<int>& vec = numsMap[target];
		return numsMap[target][rand() % vec.size()];
	}
};

int main() {
	vector <int> nums = { 1, 2, 3, 3, 3 };
	int target = 
	Solution* obj = new Solution(nums);
	unordered_map<int, vector<int>> numsMap = obj->pick(target);


