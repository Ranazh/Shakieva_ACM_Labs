#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NumMatrix {
public:
	vector<vector<int>> prefixSum;
	NumMatrix(vector<vector<int>>& matrix) {
		if (matrix.size() != 0) {
			int row = matrix.size();
			int col = matrix[0].size();
			prefixSum = matrix;
			for (int i = 1; i < col; ++i) {
				prefixSum[0][i] += prefixSum[0][i - 1];
			}
			for (int i = 1; i < row; ++i) {
				prefixSum[i][0] += prefixSum[i - 1][0];
			}
			for (int i = 1; i < row; ++i) {
				for (int j = 1; j < col; ++j) {
					prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0) return prefixSum[row2][col2];
		if (col1 == 0) return prefixSum[row2][col2] - prefixSum[row1 - 1][col2];
		if (row1 == 0) return prefixSum[row2][col2] - prefixSum[row2][col1 - 1];
		return prefixSum[row2][col2] - prefixSum[row1 - 1][col2] - prefixSum[row2][col1 - 1] + prefixSum[row1 - 1][col1 - 1];
	}
};

int main()
{
	vector<vector<int>> matrix = { {3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7}, {1, 0, 3, 0, 5} };
	NumMatrix* obj = new NumMatrix(matrix);
	int ans = obj->sumRegion(2, 1, 4, 3);
	cout << ans;

	return 0;
}

