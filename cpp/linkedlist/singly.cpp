#include <iostream>

using namespace std;

int len;

struct ListNode {
	int data;
	ListNode *next;
};

void show(ListNode *head) {
	cout << "\n\tList: ";
	if(len != 0) {
		while(head != NULL) {
			cout << head->data << "->";
			head = head->next;
		}
		cout << "NULL" << "\tLength: " << len << endl;	
	} else {
		cout << "\n\tEmpty List";
	}
}

void insert(ListNode **head) {
	int data;
	cout << "\nEnter data: ";
	cin >> data;
	if(len == 0 && *head == NULL) {
		cout << "\n\tList is empty. Creating list";
		*head = new ListNode;
		(*head)->data = data;
		(*head)->next = NULL;
	} else {
		int pos;
		cout << "\nEnter position: ";
		cin >>pos;
		if(pos > len + 1) {
			cout << "\n\tInvalid Position!";
			return;
		} else {
			ListNode *node = new ListNode;
			node->data = data;

			if(pos == 1) {
				node->next = *head;
				*head = node;
			} else {

				ListNode *p = *head;

				for(int i = 1; i < pos-1; i++)
					p = p->next;

				node->next = p->next;
				p->next = node;
			}
		}
	}
	len++;
}

void remove(ListNode **head) {
	ListNode *p = *head;

	if(len == 0) {
		cout << "\n\tNothing to remove!";
		return;
	}

	if(len == 1) {
		cout << "\n\tDeleting the only node of the list";
		*head = NULL;
		delete p;
	} else {
		int pos;
		cout << "\nEnter position: ";
		cin >> pos;
		if(pos > len) {
			cout << "\n\tInvalid Position!";
			return;
		} else {
			if(pos == 1) {
				(*head) = (*head)->next;
				p->next = NULL;
				delete p;
			} else {
				for(int i = 1; i < pos-1; i++)
					p = p->next;

				ListNode *node = p->next;
				p->next = node->next;
				delete node;
			}
		}
	}
	len--;
}


int main() {

	int choice = 1;

	ListNode *head = NULL;

	len = 0;

	while(choice) {
		cout << "\n\n1.Insert\t2.Show\t3.Remove\t4.Exit";
		cout << "\n\nEnter choice: ";
		cin >> choice;
		switch(choice) {
			case 1: insert(&head);
					break;
			case 2: show(head);
					break;
			case 3: remove(&head);
					break;
			default: cout << "Exiting..." << endl;
					 choice = 0;
		}
	}

	return 0;	
}