#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDbLinkedList
{
protected:
	int _Size = 0;
public:

	class Node
	{
	public:
		Node* prev;
		T value;
		Node* next;
	};

	Node* head = NULL;

	void InsertAtBeginning(T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = head;
		new_node->prev = NULL;

		if (head != NULL)
			head->prev = new_node;

		head = new_node;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		if (head == NULL)
		{
			InsertAtBeginning(value);
			return;
		}

		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = NULL;

		Node* last_node = head;

		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}

		last_node->next = new_node;
		new_node->prev = last_node;
		_Size++;
	}

	Node* Find(T value)
	{
		Node* current = head;

		while (current != NULL)
		{
			if (current->value == value)
				return current;

			current = current->next;
		}

		return NULL;
	}

	void InsertAfter(Node* current, T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = current->next;
		new_node->prev = current->prev;

		if (current->next != NULL)
			current->next->prev = new_node;

		current->next = new_node;
		_Size++;
	}

	void Delete(Node* deletednode)
	{
		if (deletednode == NULL || head == NULL)
		{
			return;
		}

		if (head == deletednode)
			head = head->next;


		if (deletednode->next != NULL)
			deletednode->next->prev = deletednode->prev;

		if (deletednode->prev != NULL)
			deletednode->prev->next = deletednode->next;

		delete deletednode;
		_Size--;

	}

	void DeleteFirstNode()
	{
		if (head == NULL)
			return;

		Node* delptr = head;

		head = head->next;

		if (head != NULL)
			head->prev = NULL;

		delete delptr;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
			return;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}

		Node* last_node = head;

		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}

		if (last_node->prev != NULL)
			last_node->prev->next = NULL;

		delete last_node;
		_Size--;
	}

	void PrintList()
	{
		Node* current = head;

		while (current != NULL)
		{
			cout << current->value << ' ';

			current = current->next;
		}
		cout << endl;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void Clear()
	{

		while (_Size > 0)
		{
			DeleteFirstNode();
		}

	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(int index)
	{
		int count = 0;

		if (index > _Size - 1 || index < 0)
		{
			return NULL;
		}


		Node* current = head;
		while (current != NULL)
		{
			if (count == index)
				return current;

			current = current->next;
			count++;
		}

		return NULL;
	}

	T GetItem(int index)
	{
		Node* item_node = GetNode(index);

		return (item_node == nullptr) ? NULL : item_node->value;
	}

	bool UpdateNode(int index, T new_value)
	{
		Node* item_node = GetNode(index);

		if (item_node != NULL)
		{
			item_node->value = new_value;
			return true;
		}
		else
		{
			return false;
		}

	}

	bool InsertAfter(int index, T value)
	{
		Node* item_node = GetNode(index);

		if (item_node != NULL)
		{
			InsertAfter(item_node, value);
			return true;
		}
		else
			return false;

	}
};