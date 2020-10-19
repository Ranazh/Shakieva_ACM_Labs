#include <iostream>
#include <string>
#include <map>
#include <unordered_map>


using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n == 1) return 1;
		long long ans = 0;

		for (int i = 0; i < 100; i++) {
			ans = 0;
			while (n > 0) {
				int res = n % 10;
				ans += res * res;
				n /= 10;
			}
			if (ans == 1) return 1;
			n = ans;
		}
		return 0;
	}
};

int main() {
	int k;
	cin >> k;
	Solution* obj = new Solution();

	cout << obj->isHappy(k);
	return 0;
}



