#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T value;
	Node<T>* next;
};

template <class T>

class Stack
{
	Node<T>* _top;

public:
	Stack()
	{
		_top = NULL;
	}

	bool IsEmpty()
	{
		return (_top == NULL);
	}

	void Display()
	{
		cout << "Display Stack Items: \n";

		if (IsEmpty())
		{
			cout << "Stack Is Empty!\n";
			return;
		}

		Node<T>* temp = _top;

		while (temp != NULL)
		{
			cout << temp->value << ' ';

			temp = temp->next;
		}
		cout << endl;
	}

	void Push(T value)
	{
		Node<T>* new_node = new Node<T>;
		new_node->value = value;
		new_node->next = _top;
		_top = new_node;
	}

	T Peek()
	{
		return _top->value;
	}

	T Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack Is Empty!\n";
			return NULL; 
		}

		T value = _top->value;
		_top = _top->next;
		return value;
	}

	int Count()
	{
		int count = 0;

		Node<T>* temp = _top;

		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}

		return count;
	}

	bool IsFound(T value)
	{
		Node<T>* temp = _top;

		while (temp != NULL)
		{
			if (temp->value == value)
				return true;

			temp = temp->next;
		}
		return false;
	}

	bool IsFull()
	{
		// if heab or memory is full can be not create new node
		Node<T>* ptr = new Node<T>;
		if (ptr == NULL)
		{
			cout << "The Stack is Full , Cannot Add More Items\n";
			return true;
		}
		return false;
	}

};

int main()
{
	Stack<char> stk;

	stk.Push('d');
	stk.Push('e');
	stk.Push('m');
	stk.Push('h');
	stk.Push('a');

	stk.Display();
	
	stk.Push('-');
	cout << "peek => " << stk.Peek() << '\n';
	cout << "push => " << stk.Pop() << '\n';
	cout << "count => " << stk.Count() << '\n';

	stk.Display();

	system("pause>0");
	return 0;
}