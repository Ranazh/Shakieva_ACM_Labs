#include <iostream>
#include <vector>
#include <string>

using namespace std;

class  ReverseWords {
public:
	string reverseWords(string s) {

		int start = 0, end = s.size() - 1;
		bool word = false;
		vector<string> str;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (word) {
					end = i;
					str.push_back(s.substr(start, end - start));
					word = false;
				}
			}
			else if (!word) {
				start = i;
				word = true;
			}
		}
		//if after the last word is not having a whitespace 
		if (word) {
			str.push_back(s.substr(start, s.size() - start));
		}
		//reversinth the 
		reverse(str.begin(), str.end());
		string result;
		for (auto& word : str) {
			if (!result.empty())
				result += ' ';
			result += word;
		}

		return result;
	}
};
int main()
{
	ReverseWords* obj = new ReverseWords();
	string s;
	getline(cin, s);
	cout << obj->reverseWords(s);
	return 0;
}