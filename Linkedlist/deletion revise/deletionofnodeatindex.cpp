// deletion of the node at index

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

struct node *deletenodeatindex(struct node *head, int index)
{
    struct node *p, *q;

    p = head;
    q = head->next;


    int i = 0;

    if(index==0)
    {
        struct node *p;
        p=head;
        head=head->next;
        delete p;
        return head;
    }

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
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 32;
    head->next = second;

    second->data = 89;
    second->next = third;

    third->data = 78;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deletenodeatindex(head, 0);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}