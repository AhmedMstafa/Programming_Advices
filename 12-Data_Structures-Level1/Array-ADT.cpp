#include <iostream>
using namespace std;

class Array
{
	int* _Items;
	int _Size;
	int _Length;

public:
	Array(int Size) 
	{
		_Size = Size;
		_Items = new int[_Size];
		_Length = 0;
	}

	int GetSize()
	{
		return _Size;
	}

	int GetLength()
	{
		return _Length;
	}

	bool IsEmpty()
	{
		return (_Length == 0);
	}

	void Fill()
	{
		int no_of_items = 0;
		cout << "Enter Number Of Array Items\n";
		cin >> no_of_items;

		if (no_of_items > _Size)
		{
			cout << "Your Ites Exceeds Array Size\n";
		}

		for (int i = 0; i < no_of_items; i++)
		{
			cout << "Enter Item Number of " << i << endl;
			cin >> _Items[i];
			_Length++;
		}

	}

	void Display()
	{
		if (IsEmpty())
		{
			cout << "Array Is Empty!\n";
			return;
		}

		cout << "Array Items are : \n";
		for (int i = 0; i < _Length; i++)
		{
			cout << _Items[i] << '\t';
		}

		cout << endl;
	}

	int Search(int key)
	{

		for (int i = 0; i < _Length; i++)
		{
			if (_Items[i] == key)
				return i;
		}

		return -1;
	}

	void Append(short NewItem)
	{
		if (_Length < _Size)
		{
			_Items[_Length] = NewItem;
			_Length++;
		}
		else
		{
		cout << "Array is Full\n";
		}
	}

	void Insert(short Index, int NewItem)
	{

		if (Index < 0 || Index > _Size)
		{
			cout << "Indext Out Of Range!\n";
			return;
		}

		if (_Length < _Size)
		{
		for (short i = _Length; i > Index; i--)
		{
			_Items[i] = _Items[i - 1];
		}

		_Items[Index] = NewItem;
		_Length++;
		}
		else
		{
		cout << "Array is Full\n";
		}
	}

	void Delete(short Index)
	{
		if (Index < 0 || Index > _Size)
		{
			cout << "Indext Out Of Range!\n";
			return;
		}

		for (short i = Index; i < _Length - 1; i++)
		{
			_Items[i] = _Items[i + 1];
		}

		_Length--;

	}

	void Enlarge(int NewSize)
	{
		if (NewSize <= _Size)
		{
			cout << "New Size Must Be Larger Than Current Size \n";
			return;
		}

		_Size = NewSize;

		int* Old = _Items;
		_Items = new int[NewSize];

		for (short i = 0; i < _Length; i++)
		{
			_Items[i] = Old[i];
		}


		delete[]Old;
	}

	int GetItem(short Index)
	{
		return _Items[Index];
	}

	void Marge(Array arr2)
	{
		int NewSize = (arr2.GetSize() + _Size);

		_Size = NewSize;

		int* Old = _Items;

		_Items = new int[NewSize];

		short i;

		for (i = 0; i < _Length; i++)
		{
			_Items[i] = Old[i];
		}

		short j = i;
		for (short i = 0; i < arr2.GetLength(); i++)
		{
			_Items[j++] = arr2.GetItem(i);
			_Length++;
		}

		delete[] Old;
	}
};

int main()
{
	cout << "Array ADT \n";
	cout << "Enater Array 1 Size \n";
	int ArraySize = 0;
	cin >> ArraySize;

	Array arr(ArraySize);

	arr.Fill();

	arr.Display();

	cout << "Enate Array 2 Size \n";
	cin >> ArraySize;

	Array arr2(ArraySize);

	arr2.Fill();

	arr2.Display();

	arr.Marge(arr2);

	arr.Display();

	cout << "Array Size = " << arr.GetSize() << " While Length = " << arr.GetLength() << endl;
	/*
	cout << "Enter The Value To Search For \n";
	short key;
	cin >> key;
	short Index = arr.Search(key);
	if (Index == -1)
		cout << "Item Not Found! \n";
	else
		cout << "Item Item Found In Index : " << Index << endl;

	cout << "Enter Item To Append To Array\n";
	short NewItem = 0;
	cin >> NewItem;
	arr.Append(NewItem);
	arr.Display();

	cout << "Enter Item To Insert In Array \n";
	cin >> NewItem;
	cout << "Enter The Item Index \n";
	cin >> Index;
	arr.Insert(Index, NewItem);

	arr.Display();

	cout << "Enter Deleted Item Index \n";
	cin >> Index;
	arr.Delete(Index);
	arr.Display();

	int NewSize = 0;
	cout << "Enter New Size\n";
	cin >> NewSize;
	arr.Enlarge(NewSize);

	cout << "Array Size = " << arr.GetSize() << " While Length = " << arr.GetLength() << endl;
	arr.Display();
	*/



	return 0;
}