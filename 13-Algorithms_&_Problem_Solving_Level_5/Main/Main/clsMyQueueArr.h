#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:

	clsDynamicArray<T> _MyArray;

public:

	void push(T value)
	{
		_MyArray.InsertAtEnd(value);
	}

	void Print()
	{
		_MyArray.PrintList();
	}

	bool pop()
	{
		return _MyArray.DeleteFirstItem();
	}

	int Size()
	{
		return _MyArray.Size();
	}

	bool IsEmpty()
	{
		return _MyArray.IsEmpty();
	}

	void Clear()
	{
		_MyArray.Clear();
	}

	void Resize(int new_size)
	{
		_MyArray.Resize(new_size);
	}

	void Reverse()
	{
		_MyArray.Reverse();
	}

	T front()
	{
		return _MyArray.GetItem(0);
	}

	T back()
	{
		return _MyArray.GetItem(Size() - 1);
	}

	T GetItem(int index)
	{
		return _MyArray.GetItem(index);
	}

	bool UpdateItem(int index, T value)
	{
		return _MyArray.SetItem(index, value);
	}

	bool InsertAtFront(T value)
	{
		return _MyArray.IsertAtBeginning(value);
	}

	bool InsertAtBack(T value)
	{
		return _MyArray.InsertAtEnd(value);
	}

	bool InsertAfter(int index, T value)
	{
		return _MyArray.InsertAfter(index, value);
	}

	bool InsertBefore(int index, T value)
	{
		return _MyArray.InsertBefore(index, value);
	}

};
