#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& piles) {
		sort(piles.begin(), piles.end());

		int i = piles.size() - 1;
		int bob = 0;
		int sum = 0;

		while (bob < i + 1)
		{
			sum += piles[i - 1];
			i -= 2;
			bob++;
		}

		return sum;
	}
};
int main()
{
	Solution *obj = new Solution();
	vector <int> piles = { 2,4,1,2,7,8 };

	cout << obj->maxCoins(piles);

}
