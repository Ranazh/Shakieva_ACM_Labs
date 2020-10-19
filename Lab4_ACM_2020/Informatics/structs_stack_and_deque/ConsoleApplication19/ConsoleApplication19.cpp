
// Example program
#include <iostream>
#include <string>

using namespace std;

//stack struct
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
			cout << arr[s] << endl;
			--s;
		}
	}

	void back() {
		if (s == 0)
			cout << "error" << endl;
		else
			cout << arr[s] << endl;
	}

	int size() {
		return s;
	}

	void clear() {
		s = 0;
		cout << "ok" << endl;
	}

	void exit() {
		cout << "ok" << endl;
	}

};

//deque struct
struct deque {
	int arr[1000];
	int s;

	deque() {
		s = 0;
	}

	void push_front(int x) {
		for (int i = s; i > 0; --i) {
			arr[s] = arr[s - 1];
		}
		arr[0] = x;
		cout << "ok" << endl;
	}

	void push_back(int x) {
		arr[s++] = x;
		cout << "ok" << endl;
	}

	void pop_front() {
		if (s == 0)
			cout << "error" << endl;
		else {
			cout << arr[0] << endl;
			for (int i = 1; i < s; ++i) {
				arr[s - 1] = arr[i];
			}
		}
	}

	void pop_back() {
			if (s == 0)
				cout << "error" << endl;
			else {
				cout << arr[s - 1] << endl;
				s--;
			}
		}

	void front() {
			if (s == 0)
				cout << "error" << endl;
			else
				cout << arr[0] << endl;
		}

	void back() {
			if (s == 0)
				cout << "error" << endl;
			else
				cout << arr[s - 1] << endl;
		}

	void size() {
			cout << s+1 << endl;
		}

	void clear() {
			s = 0;
			cout << "ok" << endl;
		}
	

	};

	int main() {
		//stack
		stack st;

		st.push(2);
		st.push(4);
		st.push(6);

		int s = st.size();
		for (int i = 0; i < s; ++i) {
			st.pop();
		}

		//deque
		deque dec;
		dec.push_back(3);
		dec.push_back(5);
		dec.push_front(7);
		dec.front();
		dec.size();
		dec.pop_front();

		return 0;
	}
