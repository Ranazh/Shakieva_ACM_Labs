#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class rotateMatrix {
private: vector<vector<int>> data;
public:
	void rotate(vector<vector<int>>& matrix) {
		//transpose
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		//swap columns
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size() / 2; j++) {
				swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
			}
		}


	}
};
int main() {

	vector<vector<int>> nums = {
		{1,2,3,4},
		{5, 6, 7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "ROTATE MATRIX" << endl;
	rotateMatrix* obj = new rotateMatrix();
	obj->rotate(nums);

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
