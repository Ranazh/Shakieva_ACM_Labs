#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int count = 0;
		unordered_map<int, int> u;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				u[A[i] + B[j]]++;
			}
		}
		for (int i = 0; i < C.size(); i++) {
			for (int j = 0; j < D.size(); j++) {
				if (u.find(-1 * (C[i] + D[j])) != u.end())
					count += u[-1 * (C[i] + D[j])];
			}
		}
		return count;
	}
};


int main()
{
	Solution *obj = new Solution();
	vector<int> A = { 1, 2 };
	vector<int> B = { -2, -1 };
	vector<int>	C = { -1, 2 };
	vector<int> D = { 0, 2 };

	cout << obj->fourSumCount(A, B, C, D);
	return 0;
}
