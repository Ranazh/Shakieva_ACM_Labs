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

	node* partition(node* head, int x) {
		node* less = new node();//elements the less then partition
		node* more = new node();//more then partition
		node* curr1 = less;
		node* curr2 = more;
		while (head != NULL)//has next
		{
			if (head->val < x)
			{
				curr1->next = head;
				curr1 = curr1->next;
			}
			else
			{
				curr2->next = head;
				curr2 = curr2->next;
			}
			head = head->next;
		}
		curr2->next = NULL;
		curr1->next = more->next;
		return less->next;
	}

};

int main() {
	Solution*obj = new Solution;//calling the class 
	node *list1 = new node();//create a node/ the start point of linked list
	vector <int> nums1 = { 1,2,4, 5, 3, 2};//valuse to input
	for (auto x : nums1) {
		obj->push_back(list1, x);//inputing the values into the list
	}
	cout << endl << "The list: ";
	obj->printList(list1);

	int n;
	cout << "The partition elemnt is: ";
	cin >> n;//partion element

	node* ans = obj->partition(list1, n);
	cout << endl << "The modyfying list: ";
	obj->printList(ans);
	
	return 0;
}