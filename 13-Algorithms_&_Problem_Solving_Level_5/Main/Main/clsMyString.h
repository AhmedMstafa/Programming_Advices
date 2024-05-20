#pragma once
#include <iostream>
#include "clsMyStack.h"
using namespace std;

class clsMyString
{
protected:
	clsMyStack<string> _Forward;
	clsMyStack<string> _Backward;
	string _Value;

public:
	void SetItem(string value)
	{
		_Forward.push(_Value);
		_Value = value;
	}

	string GetItem()
	{
		return _Value;
	}

	__declspec(property(get = GetItem, put = SetItem)) string Value;

	void Undo()
	{
		if (!_Forward.IsEmpty())
		{
		_Backward.push(_Value);
		_Value = _Forward.Top();
		_Forward.pop();
		}
	}

	void Redo()
	{
		if (!_Backward.IsEmpty())
		{
		_Forward.push(_Value);
		_Value = _Backward.Top();
		_Backward.pop();
		}
	}

};