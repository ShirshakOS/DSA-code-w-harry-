// insert at index
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing node
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

    struct node *temp;
    temp= head;

    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->data = 77;
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    // allocating memory for nodes in heap dynamically
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    cout << "Before traversing: " << endl;
    traverse(head);

    head = insertatindex(77, 3, head);

    cout << "After traversing: " << endl;
    traverse(head);

    return 0;
}