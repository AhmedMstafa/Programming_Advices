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

void DeleteFirstNode(Node*& head)
{
    Node* Current = head, * Prev = head;

    if (head == NULL)
        return;


    if (Current->next == NULL)
    {
        head = NULL;
        delete Current;
        return;
    }

    while (Current != NULL && Current->next !=NULL)
    {
        Prev = Current;
        Current = Current->next;
    }

    Prev->next = NULL;

    delete Current;
    return;
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

    DeleteFirstNode(head);

    Print(head);
    return 0;
}
