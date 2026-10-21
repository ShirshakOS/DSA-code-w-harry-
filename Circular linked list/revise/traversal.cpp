#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

void traverse(struct node *ptr)
{
    struct node *p;
    p = ptr;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != p);
}

int main()
{
    // nodes
    struct node *head, *second, *third, *fourth;

    // circular linking
    head->data = 3;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 88;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = head;

    traverse(head);

    return 0;
}