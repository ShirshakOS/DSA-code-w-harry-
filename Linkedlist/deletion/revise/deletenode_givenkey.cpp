// delete the node of linked list whose key is given

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *deletenodeatindex(node *head, int key)
{
    struct node *p, *q;
    p = head;
    q = head->next;
    while (q->data != key && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == key)
    {
        p->next = q->next;
        delete q;
    }
    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;
    fifth = new node;

    head->data = 3; // index: 0
    head->next = second;

    second->data = 34; // index: 1
    second->next = third;

    third->data = 80; // index: 2
    third->next = fourth;

    fourth->data = 23; // index: 3
    fourth->next = fifth;

    fifth->data = 11; // index: 4
    fifth->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deletenodeatindex(head, 80);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}