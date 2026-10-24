// push operation on linked list stack

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *top = NULL;

void traverse(node *top)
{
    node *x;
    x = top;
    while (x != NULL)
    {
        cout << "Element: " << x->data << endl;
        x = x->next;
    }
}

int isFull(struct node *ptr)
{
    node *p;
    p = new node;
    if (p == NULL)
    {
        delete p;
        return 1;
    }
    else
    {
        delete p;
        return 0;
    }
}

node *push(int value, node *top)
{
    if (isFull(top))
    {
        cout << "Stack Overflow! :(\n";
        return top;
    }
    else
    {
        node *ptr;
        ptr = new node;

        ptr->data = value;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

int isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(node *tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack underflow!\n";
        return -1;
    }
    else
    {
        node *p;
        p = top;
        int x = (tp)->data;
        top = (tp)->next;
        delete p;
        return x;
    }
}

int main()
{

    top = push(33, top);
    top = push(11, top);
    top = push(68, top);
    top = push(32, top);
    top = push(88, top);

    cout << "Traversing...\n";
    traverse(top);

    cout << "Poped " << pop(top) << " out of the stack\n";

    cout << "Now traversing again:\n";

    traverse(top);

    return 0;
}