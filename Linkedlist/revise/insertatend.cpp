// insert node at the end of linked list

#include <iostream>
using namespace std;

struct node // define node structure
{
    int data;
    node *next;
};

// traverse throught the linked list from head and print
void traverse(struct node *ptr) // pass the head of the linked list
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// define function to insert node at the end of linked list
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr, *P;
    ptr = new node;
    ptr->data = data;

    P = head;

    while (P->next != NULL)
    {
        P = P->next;
    }

    P->next = ptr;
    ptr->next = NULL;

    return head;
}

int main()
{
    struct node *head, *second, *third;

    // allocate memory in heap
    head = new node;
    second = new node;
    third = new node;

    head->data = 3;
    head->next = second;

    second->data = 33;
    second->next = third;

    third->data = 99;
    third->next = NULL;

    cout << "Before: \n";
    traverse(head);

    head = insertatend(head, 88);

    cout << "After: \n";
    traverse(head);

    return 0;
}