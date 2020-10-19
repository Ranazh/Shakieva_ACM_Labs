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

	node* mergeTwoLists(node* l1, node* l2) {
		if (!l1 || !l2) {//if one of list is null
			if (l1) return l1;//if list1 has elements print it
			else return l2;//if list1 is null prit list
		}

		if (l1->val < l2->val) {//compare the value of lists
			l1->next = mergeTwoLists(l1->next, l2);//the first is less, so we go to next in the list1
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);//the list2's elmenent is less 
			return l2;
		}
	}

};

int main() {
	Solution*obj = new Solution;//calling the class 
	node *list1 = new node();//create a node/ the start point of linked list
	node *list2 = new node();
	vector <int> nums1 = { 1,2,4 };//valuse to input
	for (auto x : nums1) {
		obj->push_back(list1, x);//inputing the values into the list
	}

	list2->val = 1;
	vector <int> nums2 = { 3,4 };
	for (auto x : nums2) {
		obj->push_back(list2, x);//inputing the values into the list
	}

	cout << "The first list: ";
	obj->printList(list1);
	cout << endl << "The second list: ";
	obj->printList(list2);

	node* ans = obj->mergeTwoLists(list1, list2);//call the function
	cout << endl << "The modifying list: ";
	obj->printList(ans);
	return 0;
}