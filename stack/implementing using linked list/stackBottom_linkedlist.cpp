// implementing stack bottom operation on linked list stack

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int isFULL(node *ptr)
{
    node *n;
    n = new node;
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *push(int data, node *top)
{
    if (isFULL(top))
    {
        cout << "Stack overflow buddy :( \n";
        return topj;
    }
    else
    {
        node *p;
        p = new node;
        p->data = data;

        p->next = top;
        top = p;
        return top;
    }
}

int stackBottom(node *top)
{
    node *ptr;
    ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    node *top = NULL;

    top = push(22, top);
    top = push(33, top);
    top = push(89, top);
    top = push(31, top);

    cout << "Bottom element: " << stackBottom(top) << endl;

    return 0;
}