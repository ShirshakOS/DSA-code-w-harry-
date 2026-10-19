// delete a node with the given value

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

struct node *delete_node(struct node *head, int value)
{
    struct node *ptr, *p;
    p = head->next;
    ptr = head;
    if (head->data == value)
    {
        head = head->next;
        delete ptr;
        delete p;
        return head;
    }
    while (p != NULL)
    {
        if (p->data == value)
        {
            ptr->next = p->next;
            break;
        }
        ptr = p;
        p = p->next;
    }
    delete p;
    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;
    fifth = new node;

    head->data = 33;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 99;
    third->next = fourth;

    fourth->data = 21;
    fourth->next = fifth;

    fifth->data = 87;
    fifth->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = delete_node(head, 99);

    cout << "After update:\n";
    traverse(head);

    return 0;
}