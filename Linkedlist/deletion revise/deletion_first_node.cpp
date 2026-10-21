#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *deletefirstnode(node *head)
{
    struct node *p;
    p = head;
    head = head->next;
    delete p;
    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 3;
    head->next = second;

    second->data = 88;
    second->next = third;

    third->data = 78;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deletefirstnode(head);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}