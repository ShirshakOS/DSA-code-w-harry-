// deleting a node in between or given index

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *delete_node_at_index(struct node *head, int index)
{
    struct node *ptr, *p;
    ptr = head;
    p = head;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    i = 0;
    while (i != index)
    {
        p = p->next;
        i++;
    }

    // Now the node pointer points at the address of the node that has index one less of the passed index

    ptr->next = p->next;
    delete p;
    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    // allocate memory in heap
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 3; // index: 0
    head->next = second;

    second->data = 33; // index: 1
    second->next = third;

    third->data = 90; // index: 2
    third->next = fourth;

    fourth->data = 11; // index: 3
    fourth->next = NULL;

    cout << "Before deleting:\n";
    traverse(head);

    head = delete_node_at_index(head, 2);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}
