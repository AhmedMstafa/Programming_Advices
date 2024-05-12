#include <iostream>
using namespace std;

class Node
{
public:
	Node* prev;
	int value;
	Node* next;
};

void InsertAtEnd(Node* head, int value)
{
	Node* new_node = new Node;
	new_node->value = value;
	new_node->next = NULL;

	if (head == NULL)
	{
		new_node->prev = NULL;
		head = new_node;
	}
	

	Node* temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	new_node->prev = temp->next;
	temp->next = new_node;

}

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
		cout << " <--> " << head->value << " <--> ";
		head = head->next;
	}

	cout << "NULL \n";
}

int main()
{
	Node* head = NULL;
	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	Print(head);
	InsertAtEnd(head, 500);
	Print(head);
	InsertAtEnd(head, 600);
	Print(head);

	return 0;
}