// delete the node with given key

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

node *deletekeynode(int key, node *head)
{
    node *p, *q;
    p = head;
    q = head->next;

    if (p->data == key)
    {
        head = head->next;
        delete p;
        return head;
    }

    while (q->data != key)
    {
        p = q;
        q = q->next;
    }
    p->next = q->next;
    delete q;
    return head;
}

int main()
{
    node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 2;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 990;
    third->next = fourth;

    fourth->data = 22;
    fourth->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deletekeynode(990, head);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}