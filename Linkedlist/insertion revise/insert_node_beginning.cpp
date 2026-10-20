// insert node at the beginning

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr) // pass head of the node
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *inseratbeginning(struct node *head, int data)
{
    struct node *ptr;
    ptr = new node;
    ptr->data = data;

    ptr->next = head;

    head = ptr;

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

    third->data = 8;
    third->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = inseratbeginning(head, 99);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}