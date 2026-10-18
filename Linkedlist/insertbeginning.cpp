// insert at beginning linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

node *insertatbegining(struct node *head, int data)
{
    node *newnode;
    newnode = new node;
    newnode->data = data;

    newnode->next = head;

    return newnode;
}

int main()
{
    node *head, *first, *second, *third;

    head = new node;
    first = new node;
    second = new node;
    third = new node;

    head->data = 33;
    head->next = first;

    first->data = 88;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 99;
    third->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = insertatbegining(head, 87);

    cout << "After update:\n";
    traverse(head);

    return 0;
}