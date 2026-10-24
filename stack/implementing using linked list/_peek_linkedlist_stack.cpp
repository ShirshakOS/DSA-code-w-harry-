// peek operation in linked list stack

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void traversalLinkedlist(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
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

int peek(int pos, node *top)
{
    node *p;
    p = top;
    int i = 1;
    while (i != pos && p != NULL)
    {
        p = p->next;
        i++;
    }
   if(p!=NULL)
   {
    return p->data;
   }
   else{
    return -1;
   }
}
int main()
{
    node *top = NULL;

    top = push(33, top); // position 5
    top = push(88, top); // position 4
    top = push(11, top); // position 3
    top = push(78, top); // position 2
    top = push(44, top); // position 1

    cout << "Traversing stack:\n";
    traversalLinkedlist(top);

    int position = 3; // output: 11

    cout << "The element in position " << position << " is: " << peek(position, top) << endl;

    return 0;
}