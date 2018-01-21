#include <iostream>
using namespace std;

/*
ListNode struct
Defines the link list with value and pointer to next node
*/
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int data) {
		val = data;
		next = NULL;
	}
};

/*
Utility function to print the values in the linked list
*/
void printList(ListNode* root) {
	ListNode* temp = root;
	while (temp != NULL) {
		cout << temp->val<<" ";
		temp = temp->next;
	}
	cout << endl;
}

/*
Add node at head of list
*/
ListNode* prependNode(ListNode* root,int data) {
	if (root == NULL) {
		root = new ListNode(data);
		return root;
	}
	ListNode* temp = new ListNode(data);
	temp->next = root;
	root = temp;
	return root;
}

/*
Add Node at tail of list
*/
ListNode* appendNode(ListNode* root, int data) {
	if (root == NULL) {
		root = new ListNode(data);
		return root;
	}

	ListNode* temp = root;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new ListNode(data);
	return root;
}

/*
Reverse linked list
*/
ListNode* reverse(ListNode* root) {
	if (root == NULL) {
		return root;
	}
	ListNode* temp = root;
	ListNode* curr = root;
	ListNode* prev = NULL;
	while (curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

/*
checks if there is a cycle
*/
bool findCycle(ListNode* root) {
	if (root == NULL) {
		return false;
	}
	ListNode* slow = root;
	ListNode* fast = root;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			return true;
		}
	}
	return false;
}

/*
test function
*/
int main() {
	ListNode* root = NULL;
	root = prependNode(root, 3);
	root = prependNode(root, 5);
	root = prependNode(root, 2);
	root = prependNode(root, 0);
	root = appendNode(root, 1);
	root = appendNode(root, 9);
	root = appendNode(root, 4);
	printList(root);
	root = reverse(root);
	printList(root);
	getchar();
	return 0;
}