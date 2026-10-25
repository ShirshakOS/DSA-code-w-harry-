#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traverse(node *head)
{
    node *ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    node *head, *second, *third, *tail;

    head = new node;
    second = new node;
    third = new node;
    tail = new node;

    head->data = 3;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 3;
    third->next = tail;

    tail->data = 3;
    tail->next = head;

    traverse(head);

    return 0;
}