// insert after a node

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

struct node *insertafternode(struct node *head, int data, struct node *prevNode)
{
    struct node *ptr;
    ptr = new node;
    ptr->data = data;

    ptr->next = prevNode->next;

    prevNode->next = ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 33;
    head->next = second;

    second->data = 323;
    second->next = third;
    third->data = 90;
    third->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertafternode(head, 32, second);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}