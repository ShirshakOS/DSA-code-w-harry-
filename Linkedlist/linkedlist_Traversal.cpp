// traversal in linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *Next; // Self referencing structure
};
void LinkedlistTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->Next;
    }
}
int main()
{
    Node *head, *first, *second, *third;

    // Allocating memory for Nodes in Heap
    head = new Node;
    first = new Node;
    second = new Node;
    third = new Node;

    // Link head and first node
    head->data = 7;
    head->Next = first;

    // Link first node and second node
    first->data = 11;
    first->Next = second;

    // Link second node and third node
    second->data = 99;
    second->Next = third;

    // Terminate the list and the third node
    third->data = 8;
    third->Next = NULL;

    LinkedlistTraversal(head);
    return 0;
}
