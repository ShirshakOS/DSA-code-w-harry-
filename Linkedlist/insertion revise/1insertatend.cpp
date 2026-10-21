// insert at the end of the linked list

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

struct node *insertatend(struct node *head, int data)
{
    struct node *p, *ptr;
    ptr = new node;
    ptr->data = data;
    p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 3;
    head->next = second;

    second->data = 99;
    second->next = third;

    third->data = 222;
    third->next = fourth;

    fourth->data = 77
    fourth->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertatend(head, 9999);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}