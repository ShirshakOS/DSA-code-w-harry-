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

int pop(struct stack *p)
{
    if (isEmpty(p))
    {
        cout << "Stack underflow\n";
        return -1;
    }
    else
    {
        int value = p->arr[p->top];
        p->top--;
        return value;
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
    s = new struct stack;
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

    cout << "Poped " << pop(s) << " from the stack\n";

    cout << "After:\n";
    display_stack(s);

    cout << "Poped " << pop(s) << " from the stack\n";

    cout << "After:\n";
    display_stack(s);

    return 0;
}