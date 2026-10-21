// insert at the beginning of linked list

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

struct node *insertatbeginning(struct node *head, int data)
{
    struct node *p;
    p = new node;
    p->data = data;

    p->next = head;
    head = p;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 23;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 111;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = NULL;

    cout << "Before traversal:\n";
    traverse(head);

    head = insertatbeginning(head, 233);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}