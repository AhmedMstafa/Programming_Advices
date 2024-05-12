#include <iostream>
using namespace std;

class Node
{
public:
	Node* prev;
	int value;
	Node* next;
};

Node* Find(Node* head, int value)
{
	while (head != NULL)
	{
		if (head->value == value)
			return head;

		head = head->next;
	}

	return NULL;
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

void Delete(Node* & head,Node*& item)
{


	if (item == NULL || head == NULL)
		return;

	if (head == item)
	{
		head = item->next;
	}

	if (item->prev != NULL)
	{
	item->next->prev = item->prev;
	}

	if (item->next != NULL)
	{
	item->prev->next = item->next;
	}



	delete item;
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

int main()
{
	Node* head = NULL;
	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	Print(head);

	Node* N1 = Find(head,3);

	Delete(head,N1);

	Print(head);
	return 0;
}