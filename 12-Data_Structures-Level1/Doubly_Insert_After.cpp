#include <iostream>
using namespace std;

class Node
{
public:
	Node* prev;
	int value;
	Node* next;
};

void InsertAtBeginng(Node* &head, int value)
{
	Node* new_node = new Node;
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = head;


	if (head != NULL)
		head->prev = new_node;

	head = new_node;
}

Node* Find(Node* head,int item)
{
	while (head->value != NULL)
	{
		if (head->value == item)
			return head;

		head = head->next;
	}

	return NULL;
}

void InsertAfter(Node* current, int value)
{
	Node* new_node = new Node;
	new_node->value = value;
	
	new_node->next = current->next;
	new_node->prev = current;

	if (current->next != NULL)
	{
		current->next->prev = new_node;
	}

	current->next = new_node;

	/*
	Node* temp = head;

	while (temp->value != item && temp->value != NULL)
	{
		temp = temp->next;
	}

	if (temp->value == NULL) return;
	*/



}

void PrintList(Node* head)
{
	if (head == NULL) return;

	if (head->prev != NULL)
		cout << head->prev->value;
	else
		cout << "NULL ";

	while (head != NULL)
	{
		cout << " <--> " << head->value << " <--> ";
		head = head->next;
	}

	if (head != NULL)
		cout << head->next->value ;
	else
		cout << "NULL ";

	cout << endl;

}


int main()
{
	Node* head = NULL;
	InsertAtBeginng(head, 1);
	InsertAtBeginng(head, 2);
	InsertAtBeginng(head, 3);
	InsertAtBeginng(head, 4);
	InsertAtBeginng(head, 5);

	PrintList(head);

	Node* N1 = Find(head, 2);

	InsertAfter(N1, 500);

	PrintList(head);
	return 0;
}
