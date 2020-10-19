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

	int getcount(node *head)//amount elements in list
	{
		node* current = head;
		int count = 0;
		while (current != NULL)
		{
			count++;
			current = current->next;
		}
		return count;
	}

	node *intersection(int len, node* headMax, node* headMin) {
		while (len--) {//skip the first elemnts untill len != 0
			headMax = headMax->next;
		}
		while (headMax != NULL && headMax != NULL)
		{
			if (headMax == headMin)
				break;
			headMax = headMax->next;
			headMin = headMin->next;
		}
		return headMax;
	}
	node *getIntersectionNode(node *headA, node *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;

		int len = 0;
		int lenA = getcount(headA), lenB = getcount(headB);

		if (lenA > lenB) {
			len = lenA - lenB;
			return intersection(len, headA, headB);
		}
		else {
			len = lenB - lenA;
			return intersection(len, headB, headA);
		}
		return headA;



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
	int x = 4;
	cout << "The first list: ";
	obj->printList(list1);
	cout << endl << "The second list: ";
	obj->printList(list2);

	node* ans = obj->getIntersectionNode(list1, list2);
	cout << endl << "The intersection of lists: " << x;
	obj->printList(ans);

	return 0;
}