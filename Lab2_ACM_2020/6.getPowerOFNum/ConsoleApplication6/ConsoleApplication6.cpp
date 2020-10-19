#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	int getKth(int lo, int hi, int k) {
		vector<pair<int, int>> numPower;
		int i = lo;
		while (i <= hi) {
			int power = 0;
			int num = i;
			while (num != 1) {
				if (num % 2 == 0) {
					num /= 2;
					power++;
				}
				else {
					num = 3 * num + 1;
					power++;
				}
			}
			numPower.push_back(make_pair(power, i));
			i++;
		}
		sort(numPower.begin(), numPower.end());

		return numPower[k - 1].second;
	}
};

int Power(int n, int cal) {
	if (n == 1) return 1;
	else if (n % 2 == 0)return Power(n / 2, cal++);
	else {
		int num = (3 * n + 1);
		return Power(num, cal++);
	}

}
int main()
{
	Solution *obj = new Solution();
	int lo, hi, k;
	cin >> lo >> hi >> k;

	cout << obj->getKth(lo, hi, k);

}