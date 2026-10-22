// insert first node in circular linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traverse(node *ptr)
{
    node *p = ptr;

    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != p);
}

node *insert_beginning(node *head, int data)
{
    node *ptr, *q;
    ptr = new node;
    ptr->data = data;

    q = head;

    while (q->next != head)
    {
        q = q->next;
    }

    q->next = ptr;
    ptr->next = head;

    head = ptr;

    return head;
}

int main()
{
    // circular linked list

    node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 22;
    head->next = second;

    second->data = 21;
    second->next = third;

    third->data = 99;
    third->next = fourth;

    fourth->data = 77;
    fourth->next = head;

    cout << "Before insertion:\n";
    traverse(head);

    head = insert_beginning(head, 69);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}