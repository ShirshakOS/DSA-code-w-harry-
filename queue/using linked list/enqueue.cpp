#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

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

    enqueue(3, &f, &r);
    enqueue(43, &f, &r);
    enqueue(2, &f, &r);
    cout << "Traversing:\n";
    linkedlist_traversal(f);

    return 0;
}