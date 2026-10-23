#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(stack *ptr)
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

void push(int value, stack *ptr)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow\n";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void display_stack(struct stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        cout << "Element: " << ptr->arr[i] << endl;
    }
}
int main()
{
    struct stack *p;
    p=new struct stack;
    p->size = 5;
    p->top = -1;
    p->arr = new int[p->size];
    

    push(33, p);

    push(99, p);

    display_stack(p);

    return 0;
}