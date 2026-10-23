// creation of stack using array in structure
// isEmpty() and isFull()

#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s;
    s=new struct stack;
    s->top = -1;
    s->size = 6;
    s->arr = new int[s->size];

    cout<<"Stack has been created\n";

    if (isEmpty(s))
    {
        cout << "The stack is empty";
    }
    else
    {
        cout << "The stact is not empty";
    }

    if (isFull(s))
    {
        cout << "\nThe stack is full";
    }
    else
    {
        cout << "\nThe stack is not full";
    }
    return 0;
}
