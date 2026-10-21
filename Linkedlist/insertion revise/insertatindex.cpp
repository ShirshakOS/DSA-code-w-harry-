// insert at the given index of the linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr, *p;

    ptr = new node;

    ptr->data = data;
    p = head;

    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 33;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 3232;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertatindex(head, 999, 2);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}
