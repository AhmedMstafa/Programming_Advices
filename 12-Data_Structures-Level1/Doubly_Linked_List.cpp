#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node<T>* prev;
    T value;
    Node<T>* next;
};

template <class T>
class DoublyLinkedList
{
    Node<T>* _head;

public:
    DoublyLinkedList()
    {
        _head = NULL;
    }

    bool IsEmpty()
    {
        return (_head == NULL);
    }

    void PrintNodeDetails(Node<T>* temp)
    {

        if (temp->prev != NULL)
            cout << temp->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << temp->value << " <--> ";

        if (temp->next != NULL)
            cout << temp->next->value << "\n";
        else
            cout << "NULL";

    }

    void PrintListDetails()

    {
        cout << "\n\n";
        Node<T>* temp = _head;

        while (temp != NULL) {
            PrintNodeDetails(temp);
            temp = temp->next;
        }
    }


    void PrintList()

    {
        cout << "NULL <--> ";
        Node<T>* temp = _head;
        while (temp != NULL) {
            cout << temp->value << " <--> ";
            temp = temp->next;
        }
        cout << "NULL";

    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "The List Is Empty!\n";
            return;
        }

        Node<T>* temp = _head;
        while (temp != NULL)
        {
            cout << temp->value << ' ';
            temp = temp->next;
        }

        cout << '\n';
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

    void InsertAtBeginning(T value)
    {
        Node<T>* new_node = new Node<T>;
        new_node->value = value;
        new_node->next = _head;
        new_node->prev = NULL;

        if (_head != NULL)
            _head->prev = new_node;

        _head = new_node;
    }

    void InsertAtEnd(T value)
    {
        if (IsEmpty())
        {
            InsertAtBeginning(value);
            return;
        }

        Node<T>* new_node = new Node<T>;
        new_node->value = value;
        new_node->next = NULL;

        Node<T>* last_node = _head;

        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }

        new_node->prev = last_node;
        last_node->next = new_node;
    }

    void InsertAfter(T prev_value, T value)
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }

        Node<T>* new_node = new Node<T>;
        new_node->value = value;
        new_node->next = NULL;

        Node<T>* current = Find(prev_value);

        if (current == NULL)
        {
            cout << "Node Not Found!\n";
            return;
        }

        new_node->next = current->next;
        new_node->prev = current;

        if (current->next != NULL)
            current->next->prev = new_node;

        current->next = new_node;
    }

    void DeleteFirstNode()
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }

        Node<T>* delptr = _head;

        _head = _head->next;

        if (_head != NULL)
            _head->prev = NULL;

        delete delptr;
    }

    void DeleteLastNode()
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }

        Node<T>* current = _head;

        if (current->next == NULL)
        {
            _head = NULL;
            delete current;
            return;
        }

        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node<T>* temp = current->next;
        current->next = NULL;
        delete temp;

    }

    void Delete(T value)
    {
        if (IsEmpty())
        {
            cout << "List Is Empty!\n";
            return;
        }

        Node<T>* current = Find(value);

        if (current == NULL)
        {
            cout << "Node Not Found!\n";
            return;
        }

        if (_head == current)
            _head = _head->next;

        if (current->next != NULL)
            current->next->prev = current->prev;

        if (current->prev != NULL)
            current->prev->next = current->next;

        delete current;
    }

};

int main()
{

    DoublyLinkedList<short> dlst;

    dlst.InsertAtBeginning(1);

    dlst.DeleteLastNode();

    if (dlst.Find(1))
        cout << "Node Is Found\n";
    else
        cout << "Node Not Found\n";

    dlst.Display();

    return 0;
}