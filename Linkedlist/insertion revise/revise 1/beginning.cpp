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

struct node *insertatbeginning(struct node *head, int data)
{
    struct node *ptr;
    ptr = new node;

    ptr->data = data;
    ptr->next = head;
    head = ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 32;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 99;
    third->next = fourth;

    fourth->data = 77;
    fourth->next = NULL;

    cout << "Before insertion:\n";
    traverse(head);

    head = insertatbeginning(head, 332);

    cout << "After insertion:\n";
    traverse(head);

    return 0;
}