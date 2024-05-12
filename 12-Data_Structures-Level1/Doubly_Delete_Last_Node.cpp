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

	/*
	void DeleteLastNode(Node*& head)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		delete head;
	}

	Node* temp = head;
	
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;

	delete temp;
}
	*/

void DeleteLastNode(Node*& head)
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		return;
	}

	Node* current = head;

	while (current->next->next != NULL)
	{
		current = current->next;
	}

	Node* temp = current->next;

	current->next = NULL;

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

	DeleteLastNode(head);

	Print(head);
	return 0;
}