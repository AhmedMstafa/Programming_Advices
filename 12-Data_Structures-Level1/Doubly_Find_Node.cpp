#include <iostream>
; using namespace std;

class Node
{
public:
    Node* prev;
    int value;
    Node* next;
};

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

void InsertAtBeginning(Node*& head, int value)
{
    Node* new_node = new Node;
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

void PrintNodeDetails(Node* head)
{
    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << '\n';
    else
        cout << "NULL";
}

void Print(Node* head)
{
    while (head != NULL)
    {
        PrintNodeDetails(head);
        head = head->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);

    Print(head);
    int item = 0;
    cout << "Enter item to search for: ";
    cin >> item;

    if (Find(head, item))
        cout << "item found.";
    else
        cout << "item not foud.";
    return 0;
}
