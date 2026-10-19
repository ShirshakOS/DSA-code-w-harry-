// insert at the beginning

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

void traverse(struct node *ptr) // pass the head node
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *insertatbeginning(node *head, int data)
{
    node *ptr, *p;
    ptr = new node; // allocate memory for new node

    ptr->data = data;
    ptr->next = head;

    head = ptr;

    return head;
}

int main()
{
    node *head, *first, *second, *third;

    // allocate memory for nodes in heap
    head = new node;
    first = new node;
    second = new node;
    third = new node;

    head->data = 7;
    head->next = first;

    first->data = 21;
    first->next = second;

    second->data = 90;
    second->next = third;

    third->data = 17;
    third->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = insertatbeginning(head, 39);

    cout << "After update:\n";
    traverse(head);

    return 0;
}