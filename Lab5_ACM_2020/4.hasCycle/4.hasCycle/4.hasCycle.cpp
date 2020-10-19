#include <iostream>
#include <string>
#include <vector>

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

	bool hasCycle(node *head) {
		if (!head) return false;//if null node
		node* curr = head;//checking node, since the staert point
		while (curr->next) {//has next element
			if (curr->next < head) return false;//if next element less then the adress of the first
			if (curr->next <= curr) return true;//else if the link range in the first to last element
			curr = curr->next;
		}
		return false;//if elemnt more then last, or cycle is not exist
	}

};

int main() {
	Solution*obj = new Solution;//calling the class 
	node *list1 = new node();//create a node/ the start point of linked list
	vector <int> nums1 = { 1,2,4 };//valuse to input
	for (auto x : nums1) {
		obj->push_back(list1, x);//inputing the values into the list
	}
	node* x = new node();
	x->val = 5;
	x->next = list1;

	cout << "The list: ";
	obj->printList(list1);

	if (obj->hasCycle(list1))
		cout << "true";
	else cout << "false";//call the function
	return 0;
}