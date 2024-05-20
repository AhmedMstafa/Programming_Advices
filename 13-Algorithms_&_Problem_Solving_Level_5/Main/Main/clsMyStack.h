#pragma once
#include <iostream>
#include "clsMyQueue.h"
using namespace std;

template <class T>

class clsMyStack:public  clsDblinkedList<T>
{
public:

	void push(T item)
	{
		clsDblinkedList<T>::_MyList.InsertAtBeginning(item);
	}

	T Top()
	{
		return clsDblinkedList<T>::front();
	}

	T Bottom()
	{
		return clsDblinkedList<T>::back();
	}

};