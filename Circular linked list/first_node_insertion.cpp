// linked list node insertion at first node

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr, *p;
    p = new node;
    p->data = data;

    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    p->next = head;
    ptr->next = p;
    head = p;

    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 2;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 3;
    third->next = head;

    cout << "Before insertion: " << endl;
    traverse(head);

    head = insertatfirst(head, 22);

    cout<< "After insertion:\n";
    traverse(head);

    return 0;
}