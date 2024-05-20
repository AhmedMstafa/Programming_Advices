#pragma once
#include <iostream>
#include "clsMyStack.h"
using namespace std;

class clsMyString  : public clsMyStack<string>
{
private:

	string _Value;
	int _Count;

public:
	clsMyString()
	{
		_Value = "";
		_Count = 0;
	}
	void SetValue(string value)
	{
		clsMyStack<string>::push(value);
	}

	string GetValue()
	{
		clsMyStack<string>::GetItem(_Count);
	}

	_declspec(property(get = GetValue, put = SetValue)) string Value;

};