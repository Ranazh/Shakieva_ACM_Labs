#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<pair<int, int>> p;
		vector<vector<int>> a(K, vector<int>(2));
		for (int i = 0; i < points.size(); i++) {
			int x = points[i][0], y = points[i][1];
			int dis = x * x + y * y;
			p.push_back({ dis,i });
		}
		sort(p.begin(), p.end());
		for (int i = 0; i < K; i++) {
			a[i][0] = points[p[i].second][0];
			a[i][1] = points[p[i].second][1];
		}
		return a;
	}
};
int main()
{
	Solution *obj = new Solution();
	vector<vector<int>> v = { {1, 3},{-2, 2} };
	int k = 1;
	vector<vector<int>> ans = obj->kClosest(v, k);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << ", ";
		}
		cout << endl;
	}

}