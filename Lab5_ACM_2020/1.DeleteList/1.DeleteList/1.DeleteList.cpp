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

	//lets create a function to delete a node
	void deleteNode(node* node, int n) {
		while (node->next != NULL) {
			if (node->val == n) {//find the node
				break;
			}
			node = node->next;//go through thr list to find needed node
		}
		if (node->next == NULL) {//if node is last
			node = NULL;
			return;
		}
		node->val = node->next->val;
		node->next = node->next->next;
	}

	
};

int main() {
	Solution*obj = new Solution;//calling the class 
	node *head = new node();//create a node/ the start point of linked list
	vector <int> nums = { 4,5,1,9 };//valuse to input
	for (auto x : nums) {
		obj->push_back(head, x);//inputing the values into the list
	}
	obj->printList(head);
	
	int n;
	cout << endl << "Delete the node with value: ";
	cin >> n;
	obj->deleteNode(head, n);//call the function
	cout << endl << "Print the modifying list: ";
	obj->printList(head);
	return 0;
}