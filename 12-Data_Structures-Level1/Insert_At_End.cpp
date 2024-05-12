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

Node* Find(Node* head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
            return head;

        head = head->next;
    }
    return NULL;
}


void InsertAtEnd(Node* &head, int value)
{
    Node* new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node* last_node = head;

    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    return;




}

void Print(Node* head)
{
    while (head != NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtBeginnig(head, 0);

    Print(head);
    return 0;
}
