// how to traverse through a linked list?
#include <iostream>
using namespace std;

// creating node structure
struct node
{
    int data;
    node *next; // self referencing node
};

// traversing function
void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// main function
int main()
{
    // creating nodes
    node *head, *first, *second, *third;

    // allocating memory dynamically for nodes in heap
    head = new node;
    first = new node;
    second = new node;
    third = new node;

    // linking..
    // head to first node
    head->data = 10;
    head->next = first;

    // first to second node
    first->data = 323;
    first->next = second;

    // second node link with third node
    second->data = 12;
    second->next = third;

    // third node terminate
    third->data = 21;
    third->next = NULL;

    traverse(head);

    return 0;
}