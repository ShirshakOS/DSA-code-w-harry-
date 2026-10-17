// inserting a node in linked list at the beginning
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next; // self referencing structure
};
void traverse(node *ptr) // should pass the head node referece
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
node *insert_beginning(int data, node *head)
{
    node *add;
    add = new node;
    add->data = data;
    add->next = head;
    return add;
}
int main()
{
    node *head, *first, *second;

    // allocating memory for nodes in heap
    head = new node;
    first = new node;
    second = new node;

    // linking head node and first node
    head->data = 8;
    head->next = first;

    // linking first node and second node
    first->data = 4;
    first->next = second;

    // terminate second node
    second->data = 69;
    second->next = NULL;

    // traverse(head);

    head = insert_beginning(9, head);

    traverse(head);

    return 0;
}