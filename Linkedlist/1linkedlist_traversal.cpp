// traversal in a linked list data structure
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    node *head, *first, *second, *third;

    // Allocating memory for nodes in heap
    head = new node;
    first = new node;
    second = new node;
    third = new node;

    // linked list data: 7,19,13,90

    // linking head and the first node
    head->data = 7;
    head->next = first;

    // linking first node and second node
    first->data = 19;
    first->next = second;

    // linking second and third node
    second->data = 13;
    second->next = third;

    // Terminating third node
    third->data = 90;
    third->next = NULL;

    // Traversing through the linked list
    traverse(head);

    return 0;
}