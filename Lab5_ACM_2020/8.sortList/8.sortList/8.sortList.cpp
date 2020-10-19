#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {//struct of the node of Linked List
	int val;//value of node
	node *next;//the link to the next node
};

class Solution {//class from Leet Code
public:
	void printList(node * n) {//function to print the Linked List
		while (n != NULL) {
			cout << n->val << " ";
			n = n->next;
		}
	}
	void push_back(node * head, int n) {//To push new elemnet (node) to the list
		node* newnode = new node();
		newnode->val = n;
		newnode->next = NULL;

		if (head == NULL) {
			head = newnode;
			return;
		}

		node* last = new node();
		last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newnode;
	}

	node* sortList(node* head) {
		if (!head) return head;
		node* ans = head;
		vector <int> valNodes;
		int val = 0;
		while (ans) {
			val = ans->val;
			valNodes.push_back(val);
			ans = ans->next;
		}
		sort(valNodes.begin(), valNodes.end());

		ans = head;
		for (auto x : valNodes) {
			ans->val = x;
			ans = ans->next;
		}

		return head;
	}

};

int main() {
	Solution*obj = new Solution;//calling the class 
	node *list1 = new node();//create a node/ the start point of linked list
	node *list2 = new node();
	vector <int> nums1 = { 1,1,0 };//valuse to input
	for (auto x : nums1) {
		obj->push_back(list1, x);//inputing the values into the list
	}

	cout << "The list: ";
	obj->printList(list1);
	cout << endl;
	cout << "The sorted list: ";
	node* ans = obj->sortList(list1);
	obj->printList(ans);
	

	return 0;
}