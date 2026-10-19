// delete the first node of the linked list

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

struct node *deletefirstnode(node *head)
{
    node *ptr;
    ptr = head;
    head = head->next;
    delete ptr;

    return head;
}

int main()
{
    node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 33;
    head->next = second;

    second->data = 99;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse(head);

    head = deletefirstnode(head);

    cout << "After deletion:\n";
    traverse(head);

    return 0;
}
