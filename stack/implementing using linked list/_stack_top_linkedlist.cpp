// implementing stack top operation in linked list stack

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void linkedlistTraversal(node *top)
{
    while (top != NULL)
    {
        cout << "Element: " << top->data << endl;
        top = top->next;
    }
}

int isFull(node *top)
{
    node *ptr;
    ptr = new node;
    if (ptr == NULL)
    {
        delete ptr;
        return 1;
    }
    else
    {
        delete ptr;
        return 0;
    }
}

node *push(int data, node *ptr)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow!" << endl;
        return ptr;
    }
    else
    {
        node *p;
        p = new node;
        p->data = data;
        p->next = ptr;
        ptr = p;
        return ptr;
    }
}

int stackTop(node *top)
{
    return top->data;
}

int main()
{
    node *top = NULL;

    top = push(11, top);
    top = push(323, top);
    top = push(99, top);
    top = push(78, top);

    cout << "The top element in stack is: " << stackTop(top) << endl;

    return 0;
}