// traverse circular linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traverse(node *ptr)
{
    node *p;
    p = ptr;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != p);
}

int main()
{
    node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 22;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 90;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = head;

    traverse(head);

    return 0;
}