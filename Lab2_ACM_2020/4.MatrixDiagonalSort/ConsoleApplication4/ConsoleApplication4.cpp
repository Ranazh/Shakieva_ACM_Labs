#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int m = mat.size();
		int n = mat[0].size();
		for (int i = m - 2; i >= 0; i--) {
			diagsort(mat, i, 0, m, n);
		}
		for (int j = 1; j < n - 1; j++) {
			diagsort(mat, 0, j, m, n);
		}
		return mat;
	}

	void diagsort(vector<vector<int>>& mat, int p, int q, int m, int n) {
		vector<int> tosort;
		int i = p;
		int j = q;
		for (i, j; i < m && j < n; i++, j++) {
			tosort.push_back(mat[i][j]);
		}
		sort(tosort.begin(), tosort.end());
		int c = 0;
		for (i = p, j = q; i < m && j < n; i++, j++) {
			mat[i][j] = tosort[c];
			c++;
		}
	}
};
int main()
{
	Solution *obj = new Solution();
	vector<vector<int>> v = {{3, 3, 1, 1}, { 2, 2, 1, 2 }, { 1, 1, 1, 2 }};
	vector<vector<int>> ans = obj->diagonalSort(v);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}
