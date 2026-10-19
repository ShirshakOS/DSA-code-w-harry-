// insert node after the given node

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

node *insertafternode(node *head, node *prevNode, int data)
{
    node *ptr;
    ptr = new node;
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 4;
    head->next = second;

    second->data = 33;
    second->next = third;

    third->data = 11;
    third->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = insertafternode(head, second, 88);

    cout << "After update:\n";
    traverse(head);

    return 0;
}