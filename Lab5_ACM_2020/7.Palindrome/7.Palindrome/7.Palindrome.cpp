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

	node* reverseList(node* head) {
		if (!head || !head->next)
			return head;

		node* prev = head, *next = head->next;
		prev->next = NULL;

		while (next)
		{
			prev = next;
			next = prev->next;
			prev->next = head;
			head = prev;
		}

		return head;
	}

	bool isPalindrome(node* head) {
		if (head == NULL || head->next == NULL)return true;
		node *ptr1 = head;
		node *ptr2 = head;
		node *prev = NULL;
		while (ptr1 && ptr2 && ptr2->next) {
			prev = ptr1;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
		}
		node *head2 = reverseList(ptr1);
		while (head && head2) {
			if (head->val != head2->val)return false;
			head = head->next;
			head2 = head2->next;
		}
		return true;
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
	if (obj->isPalindrome(list1)) {
		cout << "The list is palindrome";
	}
	else cout << "The list is NOT palindrome";

	return 0;
}