// insert node between nodes

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

struct node *insertatindex(int data, int index, struct node *head)
{
    struct node *newnode;
    newnode = new node;

    struct node *replica;
    replica = new node;
    replica = head;

    int i = 0;
    while (i != index - 1)
    {
        replica = replica->next;
        i++;
    }

    newnode->data = data;
    newnode->next = replica->next;
    replica->next = newnode;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth;

    // allocate memory dynamically for nodes in HEAP
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;
    fifth = new node;

    head->data = 3;
    head->next = second;

    second->data = 33;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = fifth;

    fifth->data = 90;
    fifth->next = NULL; // terminate the linked list

    cout << "Before traversal:\n";
    traverse(head);

    head = insertatindex(89, 3, head);

    cout << "After traverse:\n";
    traverse(head);

    return 0;
}