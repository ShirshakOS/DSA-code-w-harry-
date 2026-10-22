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

struct node *insertafternode(struct node *head, node *prevnode, int data)
{
    struct node *p;

    p = new node;
    p->data = data;

    p->next = prevnode->next;

    prevnode->next = p;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 3;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 99;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertafternode(head, third, 69);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}