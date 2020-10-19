#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> result;
		vector<int> temp;
		bool ch = true;

		for (int i = 0; i < arr2.size(); i++) {
			for (int j = 0; j < arr1.size(); j++) {
				if (arr1[j] == arr2[i])
					result.push_back(arr2[i]);
			}
		}
		if (arr1.size() > arr2.size()) {
			for (int i = 0; i < arr1.size(); i++) {
				bool flag = false;
				for (int j = 0; j < arr2.size(); j++) {
					if (arr1[i] == arr2[j]) {
						flag = true;
						break;
					}
				}
				if (!flag) temp.push_back(arr1[i]);
			}
		}
		sort(temp.begin(), temp.end());
		result.insert(result.end(), temp.begin(), temp.end());
		return result;

	}
};

int main()
{
	Solution *obj = new Solution();
	vector<int> v1 = { 2,3,1,3,2,4,6,7,9,2,19 }, v2 = { 2,1,4,3,9,6 };

	vector<int> ans = obj->relativeSortArray(v1, v2);

	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}