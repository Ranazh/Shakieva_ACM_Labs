#include <iostream>
#include <string>
#include <regex>
#include <map>

using namespace std;

class ReverseWords {
public:
	string reverseWords(string s) {
		int start = 0;
		for (int i = 0; i < s.length(); i++) {
			if (i == s.size() - 1) {
				reverse(s.begin() + start, s.end());
			}
			if (s[i] == ' ') {
				reverse(s.begin() + start, s.begin() + i);
				start = i + 1;
			}
		}
		return s;
	}
};

int main()
{
	ReverseWords *obj = new ReverseWords();
	string s;
	getline(cin, s);

	cout << obj->reverseWords(s);
	return 0;
}