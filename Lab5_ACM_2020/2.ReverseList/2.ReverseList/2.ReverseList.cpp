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
		if (!head || !head->next)// if list consist og one element or null
			return head;

		node* prev = head, *next = head->next;
		prev->next = NULL;

		while (next)//while we have elements
		{
			prev = next;//swap elemnt with the next element
			next = prev->next;//make the nexts' link to itself
			prev->next = head;//make current link to previus element
			head = prev;//the next elemnet became current
		}

		return head;
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

	node* ans = obj->reverseList(head);//call the function
	cout << endl << "The modifying list: ";
	obj->printList(ans);
	return 0;
}