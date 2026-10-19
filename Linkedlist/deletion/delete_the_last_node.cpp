// delete the last node

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next; // self referencing structure
};

void traverse_linkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *delete_lastnode(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next=NULL)
    {
        delete head;
        return NULL;
    }
    struct node *ptr, *p;
    ptr = head;
    p = head->next;
    while (p->next != NULL)
    {
        ptr = p;
        p = p->next;
    }
    // ptr is at second last node and p is at last node

    ptr->next = NULL;
    delete p; // delete p because we dont want the address that p points to 

    return head;
}

int main()
{
    struct node *head, *second, *third;

    // allocate memory for nodes in heap
    head = new node;
    second = new node;
    third = new node;

    head->data = 3;
    head->next = second;

    second->data = 44;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    cout << "Before deletion:\n";
    traverse_linkedlist(head);

    head = delete_lastnode(head);

    cout << "After deletion:\n";
    traverse_linkedlist(head);

    return 0;
}