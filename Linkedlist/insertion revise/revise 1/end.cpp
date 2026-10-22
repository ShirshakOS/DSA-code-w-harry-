// at end

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

    head->data = 22;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 88;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertatend(head, 78);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}