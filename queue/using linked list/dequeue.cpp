#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int dequeue(node **f)
{
    node *ptr;
    ptr = *f;
    if (*f == NULL)
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    else
    {
        int a = (*f)->data;
        (*f) = (*f)->next;
        delete ptr; // deallocate memory
        return a;
    }
}

void enqueue(int data, node **f, node **r)
{
    node *n;
    n = new node;
    if (n == NULL)
    {
        cout << "Queue OverFlow!\n";
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (*f == NULL) // special case if the queue is empty beforehand
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
}

void linkedlist_traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    node *f = NULL, *r = NULL;
    enqueue(33, &f, &r);
    enqueue(3, &f, &r);
    enqueue(43, &f, &r);
    enqueue(63, &f, &r);

    cout << "Dequeued: " << dequeue(&f) << endl;
    cout << "Dequeued: " << dequeue(&f) << endl;
    cout << "Dequeued: " << dequeue(&f) << endl;
    cout << "Dequeued: " << dequeue(&f) << endl;
    cout << "Dequeued: " << dequeue(&f) << endl;

    return 0;
}