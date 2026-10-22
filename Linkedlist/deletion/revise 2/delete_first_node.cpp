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

node *deletefirstnode(node *head)
{
    node *ptr;
    ptr=head;

    head = head->next;

    delete ptr;

    return head;
}

int main()
{
    node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 322;
    head->next = second;

    second->data = 221;
    second->next = third;

    third->data = 99;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deletefirstnode(head);

    cout << "After deletion:\n";
    traverse(head);
}