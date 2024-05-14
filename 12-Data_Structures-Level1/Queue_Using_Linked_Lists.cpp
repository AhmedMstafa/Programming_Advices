#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T value ;
	Node<T>* next = NULL;
};

template <class T>
class Queue
{
	Node<T>* _front;
	Node<T>* _rear;

public:
	Queue()
	{
		_front = _rear = NULL;
	}

	bool IsEmpty()
	{
		return (_front == NULL);
	}

	void Display()
	{
		if (IsEmpty())
		{
			cout << "The Queue Is Empty!\n";
			return;
		}

		Node<T>* temp = _front;

		while (temp != NULL)
		{
			cout << temp->value << ' ';
			temp = temp->next;
		}
		cout << endl;
	}

	void Enqueue(T value)
	{
		Node<T>* new_node = new Node<T>;
		new_node->value = value;

		if (IsEmpty())
		{
			_front = _rear = new_node;
			return;
		}

		_rear->next = new_node;
		_rear = new_node;

	}

	T Dequeue()
	{
		T delvalue = -1;

		if (IsEmpty())
		{
			cout << "The Queue Is Empty!\n";
			return delvalue;
		}

		delvalue = _front->value;

		if (_front == _rear)
		{
			delete _front;
			_front = _rear = NULL;
			return delvalue;
		}

		Node<T>* delptr = _front;
		_front = _front->next;
		delete delptr;
		return delvalue;
	}

	T GetFront()
	{
		return _front->value;
	}

	T GetRear()
	{
		return _rear->value;
	}

	int Count()
	{
		Node<T>* temp = _front;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	bool IsFound(T value)
	{
		Node<T>* temp = _front;
		while (temp != NULL)
		{
			if (temp->value == value)
				return true;

			temp = temp->next;
		}
		return false;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}
};

int main()
{
	Queue<short> q;

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);

	cout << "Dequeue => " << q.Dequeue() << '\n';
	cout << "Get Front => " << q.GetFront() << '\n';
	cout << "Get Rear => " << q.GetRear() << '\n';
	cout << "Count => " << q.Count() << '\n';

	cout << "Clear!\n";
	q.Clear();
	q.Display();

	system("pause>0");
	return 0;
}