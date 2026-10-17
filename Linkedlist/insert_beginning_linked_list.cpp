// insert a node in a linked list at the beginning
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *insert_beginning(int data, node *head);

void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
node *insert_beginning(int data, node *head)
{
    node *New;
    New = new node;
    New->data = data;
    New->next = head;
    return New;
}
int main()
{
    node *head, *first, *second, *third;

    // allocating memory dynamically for nodes in heap
    head = new node;
    first = new node;
    second = new node;
    third = new node;

    // LINKING NODES:

    // head node --- first node
    head->data = 7;
    head->next = first;

    // first node --- second node
    first->data = 90;
    first->next = second;

    // second node --- third node
    second->data = 91;
    second->next = third;

    // third node ---  null
    third->data = 12;
    third->next = NULL;

    cout << "---TRAVERSING BEFORE INSERTION---\n";
    traverse(head);

    head = insert_beginning(8, head);

    cout << "---TRAVERSING AFTER INSERTION---\n";
    traverse(head);

    return 0;
}
