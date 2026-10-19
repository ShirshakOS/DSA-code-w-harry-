// delete at index

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *deleteatindex(node *head, int index)
{
    struct node *p, *q;
    p = head;
    q = head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next= q->next;
    delete q;
    return head;
}

int main()
{
    node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 3;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 99;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deleteatindex(head, 2);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}