// Example program
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	deque <int> gob;
	deque <int> shaman;
	int n, n1;
	char ch;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ch;
		switch (ch) {
		case '+': {
			cin >> n1;
			gob.push_back(n1); }
				  break;
		case '*': {
			cin >> n1;
			deque<int>::iterator it = gob.begin();
			it += (gob.size() / 2);
			it = gob.insert(it, n1); }
				  break;
		case '-': {
			shaman.push_back(gob[0]);
			gob.pop_front(); }
				  break;
		}
	}
	for (auto i = shaman.begin(); i != shaman.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}
