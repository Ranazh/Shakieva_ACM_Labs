#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end(), greater<int>());

		for (int i = 0; i < A.size() - 2; ++i)
			if (A[i] < A[i + 1] + A[i + 2])
				return A[i] + A[i + 1] + A[i + 2];

		return 0;
	}
};
int main()
{
	Solution *obj = new Solution();
	vector <int> v = { 2,1,2 };

	cout << obj->largestPerimeter (v);

}