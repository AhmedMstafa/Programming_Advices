#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;
};

void InsertAtBeginnig(Node*& head, int value)
{
    Node* new_node = new Node();
    new_node->value = value;
    new_node->next = head;

    head = new_node;
}




void Print(Node* head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void DeleteNode(Node* &head, int value)
{
    Node* Current = head;
    Node* Prev = head;

    if (head == NULL)
        return;

    if (Current->value == value)
    {
        head = Current->next;
        delete Current;
        return ;
    }
    
    while (Current != NULL && Current->value != value)
    {
        Prev = Current;
        Current = Current->next;
    }

    if (Current == NULL) return ;

    Prev->next = Current->next;

    delete Current;

}


int main()
{
    Node* head = NULL;

    InsertAtBeginnig(head, 1);
    InsertAtBeginnig(head, 2);
    InsertAtBeginnig(head, 3);
    InsertAtBeginnig(head, 4);
    InsertAtBeginnig(head, 0);

    Print(head);

    DeleteNode(head, 2);

    Print(head);
    return 0;
}
