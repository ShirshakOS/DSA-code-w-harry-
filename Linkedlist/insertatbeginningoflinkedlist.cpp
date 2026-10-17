// insert a new node at the beginning of a linked list
#include <iostream>
using namespace std;

// creating node structure
struct node
{
    int data;
    node *next;
};

void traverse_linkedlist(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

node *updatelinkedlist(int data, node *head)
{
    node *update;

    update = new node;

    update->data = 88;
    update->next = head;

    return update;
}
int main()
{
    // create nodes of the linked list data structure
    node *head, *first, *second;

    // dynamically allocate memory for the nodes in HEAP
    head = new node;
    first = new node;
    second = new node;

    // assigning nodes and linking nodes

    head->data = 12;
    head->next = first;

    first->data = 32;
    first->next = second;

    second->data = 21;
    second->next = NULL;

    cout << "---Before update---\n";
    traverse_linkedlist(head);

    head = updatelinkedlist(88, head);

    cout << "---After update---\n";
    traverse_linkedlist(head);

    return 0;
}
