#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int data) {
		val = data;
		next = NULL;
	}
};

class StackWithLL {
private:
	ListNode* head;
public:
	StackWithLL() {
		head = NULL;
	}

	void push(int data) {
		if (head == NULL) {
			head = new ListNode(data);
			return;
		}
		ListNode* temp = new ListNode(data);
		temp->next = head;
		head = temp;
	}

	struct ListNode* top() {
		return head;
	}

	void pop() {
		if (head == NULL) {
			return;
		}
		ListNode* temp = head;
		head = head->next;
		delete(temp);
	}

	void printList() {
		if (head == NULL) {
			return;
		}
		ListNode* temp = head;
		while (temp != NULL) {
			cout << temp->val<<" ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	StackWithLL* s = new StackWithLL();
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);
	s->push(6);
	s->printList();
	cout << "Top of stack : " << s->top()->val<<endl;
	s->pop();
	s->pop();
	s->printList();
	getchar();
}