#include <iostream>
using namespace std;

class Node
{
public:
    Node* prev;
    int value;
    Node* next;
};

class DoublyLinkedList
{
private:
    Node* _head;

public:
    DoublyLinkedList()
    {
        _head = NULL;
    }

    bool IsEmpty()
    {
        return (_head == NULL);
    }

    void InsertAtBeginning(int value)
    {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = _head;

        if (!IsEmpty())
            _head->prev = new_node;

        _head = new_node;
    }

    void PrintList()
    {
        if (IsEmpty())
            return;

        Node* temp = _head;

        cout << "NULL";

        while (temp != NULL)
        {
            cout << " <--> " << temp->value;
            temp = temp->next;
        }

        cout << " <--> NULL\n";
    }

    void PrintNodeDetalis(Node* Node)
    {
        if (Node->prev != NULL)
            cout << Node->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << Node->value << " <--> ";

        if (Node->next != NULL)
            cout << Node->next->value << '\n';
        else
            cout << "NULL";
       
    }

    void PrintListDetalis()
    {
        if (IsEmpty())
            return;

        Node* temp = _head;

        cout << "\n\n";
        while (temp != NULL)
        {
            PrintNodeDetalis(temp);
            temp = temp->next;
        }
    }

    Node* Find(int value)
    {
        if (IsEmpty())
            return NULL;

        Node* temp = _head;

        while (temp != NULL)
        {
            if (temp->value == value)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void InsertAfter(int NodeAfter, int value)
    {

        Node* N1 = Find(NodeAfter);

        if (N1 == NULL)
            return;

        Node* new_node = new Node;
        new_node->value = value;

        new_node->next = N1->next;
        new_node->prev = N1;

        if (N1->next != NULL)
            N1->next->prev = new_node;

        N1->next = new_node;

    }

    void InsertAtEnd(int value)
    {
        if (IsEmpty())
        {
            InsertAtBeginning(value);
        }
        else
        {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = NULL;

        Node* temp = _head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->prev = temp;
        temp->next = new_node;
        }

    }

    bool Delete(int value)
    {
        Node* NodeToDelete = Find(value);

        if (IsEmpty() || NodeToDelete == NULL)
            return false;
        
        if (NodeToDelete->value = _head->value)
            _head = _head->next;

        if (NodeToDelete->next != NULL)
            NodeToDelete->next->prev = NodeToDelete->prev;

        if (NodeToDelete->prev != NULL)
            NodeToDelete->prev->next = NodeToDelete->next;

        delete NodeToDelete;
        return true;

    }

    bool DeleteFirstNode()
    {
        if (IsEmpty())
            return false;

        Node* delptr = _head;

        _head = _head->next;

        if (_head != NULL)
               _head->prev = NULL;
        
        delete delptr;

    }

    bool DeleteLastNode()
    {
        if (IsEmpty())
            return false;

        if (_head->next == NULL)
        {
            delete _head;
            _head = NULL;
            return true;
        }

        Node* current = _head;

        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;

        current->next = NULL;

        delete temp;
        return true;
    }

};

int main()
{
    DoublyLinkedList dlst;
    dlst.InsertAtBeginning(1);
    dlst.InsertAtBeginning(2);
    dlst.InsertAtBeginning(3);
    dlst.InsertAtBeginning(4);
    dlst.InsertAtBeginning(5);

    dlst.DeleteLastNode();

    dlst.PrintList();
    if (dlst.Find(3) != NULL)
        cout << "\nNode Found\n";
    else
        cout << "\nNode Not Found\n";

    return 0;
}