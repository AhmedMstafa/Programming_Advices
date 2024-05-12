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

void InsertAfter(Node*& prev_node, int value)
{
    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();

    new_node->value = value;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
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
    InsertAtBeginnig(head, 1);
    InsertAtBeginnig(head, 2);
    InsertAtBeginnig(head, 3);
    InsertAtBeginnig(head, 4);
    InsertAtBeginnig(head, 5);

    Node* N1 = Find(head,2);

    InsertAfter(N1,500);
    Print(head);
    return 0;
}
