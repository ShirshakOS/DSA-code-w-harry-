// pop operation in stack using linked list

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *top = NULL; // declaring this node pointer globally because when passing this pointer to a function normally (wihtout address), its original value remains unchanged 
                    // however on declaring this node pointer globally we can directly use this pointer in the pop function to alter its link with other nodes

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

void linkedlistTraversal(node *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        }
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

int pop(node *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow!\n";
        return -1;
    }
    else
    {
        int x = ptr->data;
        top = ptr->next;
        delete ptr;
        return x;
    }
}

int main()
{
    top = push(33, top);
    top = push(44, top);
    top = push(88, top);

    cout << "Traversing...\n";
    linkedlistTraversal(top);

    cout << "Poped " << pop(top) << endl;

    cout << "Traverse again:\n";
    linkedlistTraversal(top);

    return 0;
}