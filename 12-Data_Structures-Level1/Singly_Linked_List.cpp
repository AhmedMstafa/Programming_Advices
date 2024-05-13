#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node* next;
};

template <class T> 
class LinkedList
{
    Node<T>* _head;

public:
    LinkedList()
    {
        _head = NULL;
    }

    bool IsEmpty()
    {
        return (_head == NULL);
    }

    Node<T>* Find(T value)
    {
        Node<T>* temp = _head;

        while (temp != NULL)
        {
            if (temp->value == value)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "The List Is Empty!\n";
        }
        else
        {
            Node<T>* temp = _head;
            while (temp != NULL)
            {
                cout << temp->value << ' ';
                temp = temp->next;
            }
            cout << '\n';
        }
    }

    void InsertAtBeginning(T value)
    {
        Node<T>* new_node = new Node<T>;
        new_node->value = value;

        new_node->next = _head;
        _head = new_node;
    }

    void InsertAtEnd(T value)
    {
        if (IsEmpty())
        {
            InsertAtBeginning(value);
        }
        else
        {
            Node<T>* new_node = new Node<T>;
            new_node->value = value;
            new_node->next = NULL;

            Node<T>* last_node = _head;
            while (last_node->next != NULL)
            {
                last_node = last_node->next;
            }

            last_node->next = new_node;
        }
    }

    void InsertAfter(T prev_node, T value)
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }

        Node<T>* item = Find(prev_node);

        if (item == NULL)
        {
            cout << "Item Not Found\n";
        }
        else
        {
            Node<T>* new_node = new Node<T>;
            new_node->value = value;

            new_node->next = item->next;
            item->next = new_node;
        }
    }
    
    void DeleteFirstNode()
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
        }
        else
        {
            Node<T>* delptr = _head;

            _head = _head->next;

            delete delptr;
        }
    }

    void DeleteLastNode()
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }
        
        Node<T>* delptr = _head;

        if (delptr->next != NULL)
        {
            Node<T>* prev = NULL;

            while (delptr->next != NULL)
            {
                prev = delptr;
                delptr = delptr->next;
            }

            prev->next = NULL;
        }
        else
        {
            _head = NULL;
        }

        delete delptr;
    }

    void Delete(T value)
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }

        Node<T>* delptr = _head;

        if (_head->value == value)
        {
            _head = _head->next;
        }
        else 
        {

        Node<T>* prev = NULL;

        while (delptr->value != value && delptr != NULL)
        {
            prev = delptr;
            delptr = delptr->next;
        }

            if (delptr == NULL)
            {
                cout << "Item Not Found\n";
                return;
            }

         prev->next = delptr->next;
        }

        delete delptr;
    }
};

int main()
{
    LinkedList<short> lst;

    lst.InsertAtBeginning(4);
    lst.InsertAtBeginning(3);
    lst.InsertAtBeginning(2);
    lst.InsertAtBeginning(1);

    lst.InsertAtEnd(5);
    lst.InsertAtEnd(5);

    lst.InsertAfter(2, 500);

    if (lst.Find(1))
        cout << "Item Is Found\n";
    else
        cout << "Item Not Found\n";

    lst.Delete(5);

    lst.Display();

    return 0;
}