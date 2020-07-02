
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


Node *reverseList(Node* head)
{
	stack<Node *> stk;

	// пушваме елементите от листа в стака
	Node* ptr = head;
	while (ptr->next != NULL) {
		stk.push(ptr);
		ptr = ptr->next;
	}

	// попваме от стака и заместваме нода със стойността
	head = ptr;
	while (!stk.empty()) {
		ptr->next = stk.top();

		ptr = ptr->next;
		stk.pop();
	}

	ptr->next = NULL;

	return head;
}

void printList(Node* head)
{
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}


int main()
{

	struct Node* head = NULL;


	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	head = reverseList(head);

	printList(head);

	return 0;
}
