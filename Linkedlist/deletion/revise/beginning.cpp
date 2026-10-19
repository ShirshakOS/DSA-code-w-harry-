#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

void traverse_linkedlist(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *delete_firstnode(struct node *head)
{
    struct node *ptr;
    ptr = head;
    head = head->next;

    delete ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    third = new node;
    second = new node;

    head->data = 3;
    head->next = second;

    second->data = 88;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse_linkedlist(head);

    head = delete_firstnode(head);

    cout << "After deletion:\n";
    traverse_linkedlist(head);

    return 0;
}