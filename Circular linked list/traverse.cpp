#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

// defining function to traverse a circular linked list
void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;

    // use do-while loop for efficient traversing of circular linked list
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new struct node;
    second = new struct node;
    third = new struct node;
    fourth = new struct node;

    // linking nodes
    head->data = 2;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = head;

    traverse(head);

    return 0;
}