#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class clsLinkedList
{
    Node* _head;
public:

    clsLinkedList()
    {
        _head = NULL;
    }

    bool IsEmpty()
    {
        return (_head == NULL);
    }

    void InsertFirst(int value)
    {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = _head;
        _head = new_node;

        /*
        if (IsEmpty())
        {
            new_node->next = NULL;
            _head = new_node;
        }
        else
        {
            new_node->next = _head;
            _head = new_node;
        }
        */

    }

    void Disblay()
    {

        Node* Temp = _head;
        while (Temp != NULL)
        {
            cout << Temp->data << " ";
            Temp = Temp->next;
        }
        cout << endl;
    }

    int Count()
    {
        int Count = 0;

        Node* Temp = _head;
        while (Temp != NULL)
        {
            Count++;
            Temp = Temp->next;
        }
        return Count;
    }

    bool IsFound(int key)
    {
        Node* Temp = _head;
        while (Temp != NULL)
        {
            if (Temp->data == key)
                return true;

            Temp = Temp->next;
        }

        return false;
    }

    void InsertBefore(int item,int value)
    {
        if (IsEmpty())
        {
            InsertFirst(value);
            return;
        }


        if (!IsFound(item))
        {
            cout << "sorry , item not found\n";
            return;
        }

        Node* new_node = new Node();
        new_node->data = value;

        Node* Temp = _head;

        while (Temp->next->data != item)
        {
            Temp = Temp->next;
        }

        new_node->next = Temp->next;
        Temp->next = new_node;

    }

    void Append(int value)
    {
        if (IsEmpty())
        {
            InsertFirst(value);
            return;
        }

        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = NULL;

        Node* Temp = _head;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = new_node;
    }

    void Delete(int item)
    {
        if (IsEmpty())
        {
            cout << "List is empty, no items to delete \n";
            return;
        }

        Node* delptr = _head;

        if (_head->data == item) // case 1 if item is first item
        {
            _head = _head->next;
            delete delptr;
            return;
        }

        if (!IsFound(item))
        {
            cout << "sorry , item not found\n";
            return;
        }

        Node* prevptr = NULL;

        while (delptr->data != item)
        {
            prevptr = delptr;
            delptr = delptr->next;
        }
        
        prevptr->next = delptr->next;
        delete delptr;

        }
      

};

int main()
{
    clsLinkedList lst;
    if (lst.IsEmpty())
        cout << "The List is Empty \n";
    else
        cout << "The List contains " << lst.Count() << endl;

    int item;
    cout << "Enter Item to insert in the list \n";
    cin >> item;
    lst.InsertFirst(item);
    lst.Disblay();
    cout << "Enter Item to insert in the list \n";
    cin >> item;
    lst.InsertFirst(item);
    lst.Disblay();
    cout << "Enter Item to insert in the list \n";
    cin >> item;
    lst.InsertFirst(item);
    lst.Disblay();
    cout << "The List contains " << lst.Count() << endl;

    cout << "Enter item to search for\n";
    cin >> item;
    if (lst.IsFound(item))
        cout << "item Found\n";
    else
        cout << "item not Found\n";

    int new_value = 0;
    cout << "Enter item and new value to insert \n";
    cin >> item;
    cin >> new_value;
    lst.InsertBefore(item, new_value);
    lst.Disblay();

    cout << "Entet item to append in list\n";
    cin >> item;
    lst.Append(item);
    lst.Disblay();

    cout << "Enter item to delete from list\n";
    cin >> item;
    lst.Delete(item);
    lst.Disblay();

    return 0;
}
