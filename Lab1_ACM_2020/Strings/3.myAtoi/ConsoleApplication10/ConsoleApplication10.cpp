// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isNumericChar(char c) //function to checking is char a digit
	{
		if (c >= '0' && c <= '9')
			return true;
		return false;
	}

	int myAtoi(string str) {
		int size = str.size();
		long long res = 0;
		bool ch = true;//to checkin the first elemnts are only digit
		int sign = 1;//positive or negative 

		if (size > 0) {
			int i = 0;
			while (i < size) {
				if (isNumericChar(str[i])) {
					//the char is digit
					ch = false;
					int temp = str[i] - '0';//convert to int
					res = 1LL * res * 10 + 1LL * temp;//input in result string

					//checking that the result is included in the range [−2^31,  2^31 − 1]
					if (res > 1LL * INT_MAX) {
						if (sign == -1)
							return INT_MIN;
						return INT_MAX;
					}
				}
				else if (str[i] == ' ') {
					if (ch == false)
						break;
				}
				else if ((str[i] == '-' || str[i] == '+') && ch == true) {
					if (str[i] == '-')
						sign = -1;
					ch = false;
				}
				else {
					return sign * res;
				}
				i++;
			}

		}
		return sign * res;
	}
};
int main()
{
	Solution *obj = new Solution();
	string s;
	cin >> s;

	cout << obj->myAtoi(s);
	return 0;
}
