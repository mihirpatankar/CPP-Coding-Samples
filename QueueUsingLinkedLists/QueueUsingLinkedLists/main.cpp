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

class QueueWithLL {
private:
	ListNode* head;
	ListNode* tail;
public:
	QueueWithLL() {
		head = NULL;
		tail = NULL;
	}

	void push(int data) {
		if (head == NULL && tail==NULL) {
			head = new ListNode(data);
			tail = head;
			return;
		}
		tail->next = new ListNode(data);
		tail = tail->next;
	}

	struct ListNode* front() {
		if (head == NULL) {
			cout << "Queue is empty !";
			return 0;
		}
		return head;
	}

	struct ListNode* pop() {
		if (head == NULL) {
			return head;
		}
		ListNode* temp = head;
		head = head->next;
		delete(temp);
		return head;
	}

	void printData() {
		if (head == NULL) {
			return;
		}
		ListNode* temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	QueueWithLL* q = new QueueWithLL();
	q->push(1);
	q->push(5);
	q->push(4);
	q->push(6);
	q->push(8);
	q->push(2);
	cout << "Front of queue : " << q->front()->val<<endl;
	q->printData();
	q->pop();
	q->printData();
	q->pop();
	q->printData();
	getchar();
}