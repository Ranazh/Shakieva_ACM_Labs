#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	string number_conversion(int number) {
		map<int, string> num_c = { {1, "One"}, {2,"Two"}, {3,"Three"}, {4, "Four"}, {5, "Five"},
								 {6, "Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10, "Ten"},
								 {11, "Eleven"}, {12, "Twelve"}, {13,"Thirteen"}, {14,"Fourteen"}, {15, "Fifteen"},
								 {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
		if (number < 20) {
			for (auto it = num_c.begin(); it != num_c.end(); ++it)
				if (it->first == number)
					return it->second;
		}
		if (number >= 90) return "Ninety";
		if (number >= 80) return "Eighty";
		if (number >= 70) return "Seventy";
		if (number >= 60) return "Sixty";
		if (number >= 50) return "Fifty";
		if (number >= 40) return "Forty";
		if (number >= 30) return "Thirty";
		if (number >= 20) return "Twenty";
		return "";
	}

	string number_h(int number) {
		string temp100 = "", temp10 = "", temp1 = "";
		int size = to_string(number).size();
		if (size == 1) return number_conversion(number) + " ";
		if (size == 3) {
			temp100 = number_conversion(number / 100);
			temp100.append(" Hundred ");
		}
		temp10 = number_conversion(number % 100);
		temp10.push_back(' ');
		if (number % 100 < 20) return temp100 + temp10;
		temp1 = number_conversion(number % 10);
		temp1.push_back(' ');
		return temp100 + temp10 + temp1;
	}
	string numberToWords(int num) {
		string ans = "";
		int size = to_string(num).size();
		if (num == 0) return "Zero";
		if (size <= 3) {
			ans = number_h(num);
		}
		else {
			if (size > 9) {
				ans.append(number_h(num / 1000000000) + "Billion ");
				num = num % 1000000000;
				size = to_string(num).size();
			}
			if (size > 6) {
				ans.append(number_h(num / 1000000) + "Million ");
				num = num % 1000000;
				size = to_string(num).size();
			}
			if (size > 3) {
				ans.append(number_h(num / 1000) + "Thousand ");
				num = num % 1000;
				size = to_string(num).size();
			}
			ans.append(number_h(num % 1000));
		}
		ans = regex_replace(ans, regex("^ +| +$|( ) +"), "$2");
		return ans;
	}
};

int main()
{
	Solution *obj = new Solution();
	int n;
	cin >> n;

	cout << obj->numberToWords(n);
	return 0;
}
