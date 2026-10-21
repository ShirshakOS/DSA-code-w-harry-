// deletion of node with key

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

struct node *delete_node_key(struct node *head, int key)
{
    struct node *p, *q;

    p = head;
    q = head->next;

    if(head->data==key)
    {
        head=head->next;
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
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 32;
    head->next = second;

    second->data = 90;
    second->next = third;

    third->data = 44;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = delete_node_key(head, 32);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}