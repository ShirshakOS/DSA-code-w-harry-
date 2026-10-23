#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop(struct stack *p)
{
    if (isEmpty(p))
    {
        cout << "The stack is empty\n";
    }
    else
    {
        p->top--;
    }
}

void display_stack(stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        cout << "Element: " << ptr->arr[i] << endl;
    }
}

int main()
{
    stack *s;
    s->size = 4;
    s->top = -1;
    s->arr = new int[s->size];

    s->arr[0] = 2;
    s->top++;

    s->arr[1] = 8;
    s->top++;

    s->arr[2] = 9;
    s->top++;

    cout << "Before:\n";
    display_stack(s);

    pop(s);

    cout << "After:\n";
    display_stack(s);

    return 0;
}