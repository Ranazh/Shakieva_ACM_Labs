#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");
	int cl; //input number of class
	string name;//input students name

	queue<string> cl9;
	queue<string> cl10;
	queue<string> cl11;

	while (cin >> cl >> name) {
		if (cl == 9) cl9.push(name);
		else if (cl == 10) cl10.push(name);
		else cl11.push(name);
	}
	while (!cl9.empty()) {
		cout << "9 " << cl9.front() << endl;
		cl9.pop();
	}
	while (!cl10.empty()) {
		cout << "10 " << cl10.front() << endl;
		cl10.pop();
	}
	while (!cl11.empty()) {
		cout << "11 " << cl11.front() << endl;
		cl11.pop();
	}

	return 0;
}
