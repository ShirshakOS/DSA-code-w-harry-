// delete the last node of linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *deletelastnode(node *head)
{
    struct node *ptr;
    struct node *q;
    q = head;
    ptr = head->next;

    while (ptr->next != NULL)
    {
        q = q->next;
        ptr = ptr->next;
    }
    q->next = NULL;
    delete ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 33;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 90;
    third->next = NULL;

    cout << "Before Deletion:\n";
    traverse(head);

    head = deletelastnode(head);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}
