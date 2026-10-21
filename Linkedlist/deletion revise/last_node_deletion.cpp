// deletion of the last node of the linked list

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

struct node *delete_last_node(struct node *head)
{
    struct node *p, *q;

    p = head;
    q = head->next;

    while (q->next != NULL)
    {
        p = q;
        q = q->next;
    }

    p->next = NULL;
    delete q;

    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 32;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 90;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = delete_last_node(head);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}