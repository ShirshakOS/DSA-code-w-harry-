// insertion of node at the head of circular linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    struct node *p;
    p = ptr;

    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != p);
}

struct node *insertatbeginning(struct node *head, int data)
{
    struct node *ptr, *q;
    ptr = new node;

    ptr->data = data;

    while (q->next != head)
    {
        q = q->next;
    }

    q->next = ptr;

    ptr->next = head;

    head = ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 12;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = head;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertatbeginning(head, 99999);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}