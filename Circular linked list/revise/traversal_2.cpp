#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    struct node *p = ptr;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != p);
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 89;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 98;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = head;

    traverse(head);

    return 0;
}