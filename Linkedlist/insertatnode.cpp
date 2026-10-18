// insert a node between nodes or at given index

#include <iostream>
using namespace std;

// create structure of node
struct node
{
    int data;
    node *next;
};

// traverse and print the linked list
void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// update head after inserting node at the given index
struct node *insertatindex(int data, node *head, int index)
{
    struct node *ptr;
    ptr = new node;

    struct node *p;
    p = new node;
    p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main()
{
    struct node *head, *first, *second;

    head = new node;   // index: 0
    first = new node;  // index: 1
    second = new node; // index: 2

    head->data = 12;
    head->next = first;

    first->data = 33;
    first->next = second;

    second->data = 99;
    second->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = insertatindex(19, head, 1);

    cout << "After update:\n";
    traverse(head);

    return 0;
}