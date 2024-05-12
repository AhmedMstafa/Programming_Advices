#include <iostream>
using namespace std;

class Node
{
public:
	Node* prev;
	int value;
	Node* next;
};

void InsertAtBeginning(Node*& head, int value)
{
	Node* new_node = new Node;
	new_node->value = value;
	new_node->next = head;
	new_node->prev = NULL;

	if (head != NULL)
		head->prev = new_node;

	head = new_node;
}

void Print(Node* head)
{
	if (head->prev != NULL)
		cout << head->prev->value;
	else
		cout << "NULL";

	while (head != NULL)
	{
		cout << " <--> " << head->value;
		head = head->next;
	}

	cout << " <--> NULL \n";
}

void DeleteFirstNode(Node*& head)
{
	if (head == NULL)
		return;

	Node* temp = head;

	head = head->next;

	if (head != NULL)
		head->prev = NULL;

	delete temp;
}

int main()
{
	Node* head = NULL;
	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	Print(head);

	DeleteFirstNode(head);

	Print(head);
	return 0;
}