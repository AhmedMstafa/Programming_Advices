#pragma once
#include <iostream>
#include "clsMyQueueArr.h"

template <class T>

class clsMyStackArr : public clsMyQueueArr<T>
{
public:
	void push(T item)
	{
		clsMyQueueArr<T>::_MyArray.IsertAtBeginning(item);
	}

	T Top()
	{
		return clsMyQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::back();
	}
};