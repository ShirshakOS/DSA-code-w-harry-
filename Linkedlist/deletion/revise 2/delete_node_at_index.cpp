#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *deleteindexnode(int index, node *head)
{
    node *p, *q;
    p = head;
    q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = q;
        q = q->next;
        i++;
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

    head = deleteindexnode(1, head);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}