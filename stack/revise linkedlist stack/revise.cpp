#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

int isEmpty(node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(node *ptr)
{
    node *p;
    p = ptr;

    if (isEmpty(ptr))
    {
        cout << "Stack underflow!\n";
        return -1;
    }
    else
    {
        int value = p->data;
        top = ptr->next;
        delete p;
        return value;
    }
}

int isFull(node *ptr)
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

node *push(int data, node *ptr)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow!\n";
        return ptr;
    }
    else
    {
        node *n;
        n = new node;
        n->data = data;
        n->next = ptr;
        top = n;
        return top;
    }
}

void traverse(node *ptr)
{

    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int peek(int pos, node *ptr)
{
    int i = 1;
    while (i != pos)
    {
        ptr = ptr->next;
        i++;
    }
    return ptr->data;
}
int main()
{

    top = push(33, top);
    top = push(11, top);

    cout << "Traversing: " << endl;
    traverse(top);

    pop(top);

    cout << "Again:\n";
    traverse(top);

    top = push(22, top);
    top = push(11, top);
    top = push(99, top);

    cout << "Again traversing:\n";
    traverse(top);

    cout << "\nPosition: 3, Element: " << peek(3, top) << endl;

    return 0;
}