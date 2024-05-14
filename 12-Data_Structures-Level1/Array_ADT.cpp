#include <iostream>
using namespace std;

template <class T>
class Array
{
    T* _Items;
    int _Length;
    int _Size;

public:
    Array(int array_size)
    {
        _Size = array_size;
        _Items = new T[_Size];
        _Length = 0;
    }

    bool IsEmpty()
    {
        return (_Length == 0);
    }

    int Length()
    {
        return _Length;
    }

    int Size()
    {
        return _Size;
    }

    void Fill()
    {
        int number_of_items = 0;
        cout << "Enter Number Of Items: ";
        cin >> number_of_items;

        if (number_of_items > _Size)
        {
            cout << "Number Of Items Exceeds Array Size\n";
            return;
        }

        for (int i = 0; i < number_of_items; i++)
        {
            cout << "Enter Item Number " << i << '\n';
            cin >> _Items[i];
            _Length++;
        }
    }

    void Dispaly()
    {
        if (IsEmpty())
        {
            cout << "Array Is Empty!\n";
            return;
        }

        for (int i = 0; i < _Length; i++)
        {
            cout << _Items[i] << ' ';
        }
        cout << endl;
    }

    int GetIndex(T item)
    {
        for (int i = 0; i < _Length; i++)
        {
            if (_Items[i] == item)
                return i;

        }

        return -1;
    }

    void Append(T item)
    {

        if (_Length >= _Size)
        {
            cout << "Array Is Full!\n";
            return;
        }

        _Items[_Length] = item;
        _Length++;
    }

    void InsertAtBeginning(T item)
    {

        if (_Length >= _Size)
        {
            cout << "Array Is Full!\n";
            return;
        }

        for (int i = _Length; i >= 0; i--)
        {
            _Items[i] = _Items[i - 1];
        }

        _Items[0] = item;
        _Length++;
    }

    void Insert(int index, T new_item)
    {
        if (IsEmpty())
        {
            cout << "Array Is Empty!\n";
            return;
        }

        if (_Length >= _Size)
        {
            cout << "Array Is Full!\n";
            return;
        }

        if (index < 0 || index > _Length)
        {
            cout << "Item Not Found!\n";
            return;
        }

        for (int i = _Length; i > index; i--)
        {
            _Items[i] = _Items[i - 1];
        }

        _Items[index] = new_item;
        _Length++;

    }

    bool IsFound(T item)
    {
        return (GetIndex(item) != -1);
    }

    void Delete(T item)
    {
        if (IsEmpty())
        {
            cout << "Array Is Empty!\n";
            return;
        }

        int index = GetIndex(item);

        if (index == -1)
        {
            cout << "Item Not Found!\n";
            return;
        }

        for (int i = index; i < _Length - 1; i++)
        {
            _Items[i] = _Items[i + 1];
        }

        _Length--;
    }

    void Enlarge(int new_size)
    {
        if (new_size <= _Size)
        {
            cout << "New Size Must Be Larger Than Current Size\n";
            return;
        }

        T* new_array = new T[new_size];
        T* temp = _Items;
        for (int i = 0; i < _Length; i++)
        {
            new_array[i] = _Items[i];
        }
        _Items = new_array;
        delete[] temp;
    }

    T GetItem(int index)
    {
        return _Items[index];
    }

    void Marge(Array<T> array2)
    {

        int new_size = _Size + array2.Size();
        T* new_array = new T[new_size];
        T* temp = _Items;

        int i = 0;

        for (i; i < _Length; i++)
        {
            new_array[i] = _Items[i];
        }

        int j = i;

        for (int i = 0; i < array2.Length(); i++)
        {
            new_array[j++] = array2.GetItem(i);
            _Length++;
        }

        _Items = new_array;
        _Size = new_size;
        delete[] temp;
        
    }

};

int main()
{
    cout << "\"Array ADT\"\n\n";

    int ArraySize = 0;
    cout << "Enter Array Size: ";
    cin >> ArraySize;
    Array<short> arr(ArraySize);

    arr.Fill();

    arr.Append(3);

    arr.Dispaly();

    cout << "Array Length is : " << arr.Length() << " And Array Size Is " << arr.Size();

    system("pause>0");
    return 0;
}
