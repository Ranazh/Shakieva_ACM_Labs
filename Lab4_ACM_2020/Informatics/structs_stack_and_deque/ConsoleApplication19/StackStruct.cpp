#include <iostream>
#include <string>

using namespace std;

struct stack {
	int arr[1000];
	int s;

	stack() {
		s = 0;
	}
	void push(int x) {
		arr[++s] = x;
		cout << "ok" << endl;
	}

	void pop() {
		if (s == 0)
			cout << "error" << endl;
		else {
			cout << arr[s - 1] << endl;
			--s;
		}
	}

	void back() {
		if (s == 0)
			cout << "error" << endl;
		else
			cout << arr[s - 1] << endl;
	}

	void size() {
		cout << s << endl;
	}

	void clear() {
		s = 0;
		cout << "ok" << endl;
	}

	void exit() {
		cout << "ok" << endl;
	}

};

int main() {
	stack st;


	st.push(3);
	st.push(5);
	st.push(7);

	for (auto x : st) {
		cout << x << " ";
	}

	return 0;
}
