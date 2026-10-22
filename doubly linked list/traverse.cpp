#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traverse_from_head(struct node *ptr) // pass the head node
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void traverse_from_end(struct node *ptr) // pass the end node
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->prev;
    }
}
int main()
{
    // create nodes
    node *head, *n2, *n3, *n4;

    head = new node;
    n2 = new node;
    n3 = new node;
    n4 = new node;

    // link nodes

    head->data = 2;
    head->prev = NULL;
    head->next = n2;

    n2->data = 11;
    n2->prev = head;
    n2->next = n3;

    n3->data = 99;
    n3->prev = n2;
    n3->next = n4;

    n4->data = 78;
    n4->next = NULL;
    n4->prev = n3;

    cout << "Traverse doubly linked list from head:\n";
    traverse_from_head(head);

    cout << "Traverse from end:\n";
    traverse_from_end(n4);

    return 0;
}