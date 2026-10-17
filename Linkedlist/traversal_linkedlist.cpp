// traversal in a linked list
#include <iostream>
using namespace std;

// Creation of nodes linked listl
struct node
{
    int data;
    node *next;
};
void traversal(node *ptr);
int main()
{
    node *head, *first, *second, *third;

    // allocating memory to nodes in heap
    head = new node;
    first = new node;
    second = new node;

    // linking head and first node
    head->data = 4;
    head->next = first;

    // linking first node and second node
    first->data = 8;
    first->next = second;

    // linking second node and third node
    second->data = 88;
    second->next = third;

    // terminating third node
    third->data = 22;
    third->next = NULL;

    traversal(head);
    return 0;
}

void traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}