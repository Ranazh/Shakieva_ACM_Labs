#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution1 {
public:
	double average(vector<int>& salary) {
		int size = salary.size();
		int mx = salary[0];
		int mn = salary[0];
		double sum = salary[0];
		for (int i = 1; i < size; i++) {
			sum += salary[i];
			mx = max(mx, salary[i]);
			mn = min(mn, salary[i]);
		}

		return (sum - mn - mx) / (size - 2);
	}
};

class Solution2 {
public:
	double average(vector<int>& salary) {
		int size = salary.size();
		sort(salary.begin(), salary.end());
		double sum = salary[1];
		for (int i = 2; i < size - 1; i++) {
			sum += salary[i];
		}

		return sum / (size - 2);
	}
};

int main()
{
	Solution1 *obj1 = new Solution1();
	Solution2 *obj2 = new Solution2();
	vector<int> v;
	int num;
	cout << "Enter Numbers" << '\n';
	while (cin >> num)
	{
		v.push_back(num);
	}
	cout << "The first solution: " << obj1->average(v) << endl;
	cout << "The second solution: " << obj2->average(v) << endl;

	return 0;
}

