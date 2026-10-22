// insert at index;

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

struct node *insertatindex(struct node *head, int index, int data)
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
    node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 1;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 33;
    fourth->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertatindex(head, 2, 89);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}