#include <iostream>
#include <string>

using namespace std;

class MinStack {
public:
	int arr[100000];
	int size;
	MinStack() {
		size = 0;
	}

	void push(int x) {
		arr[size++] = x;
	}

	void pop() {
		--size;
	}

	int top() {
		return arr[size];
	}

	int getMin() {
		int min = arr[0];
		for (int i = 1; i <= size; ++i) {
			if (min > arr[i])
				min = arr[i];
		}
		return min;
	}
};
int main()
{
	MinStack* obj = new MinStack();
	obj->push(8);
	obj->push(5);
	obj->push(13);
	obj->push(3);
	obj->push(53);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
	obj->pop();
	cout << obj->top() << endl;
	cout << param_4;
	return 0;
}
