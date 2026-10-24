#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char x, stack *ptr)
{
    ptr->top++;
    ptr->arr[ptr->top] = x;
}

void pop(stack **ptr)
{
    if (isEmpty(*ptr))
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        (*ptr)->top--;
    }
}

int parenthesisMatch(char *exp, stack *ptr)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push('(', ptr);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(ptr))
            {
                cout << "Stack underflow\n";
                return 0;
            }
            pop(&ptr);
        }
    }
    if (isEmpty(ptr))
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
    stack *sp;
    sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    // stack created

    char exp[] = ")3-2(+22";

    if (parenthesisMatch(exp, sp))
    {
        cout << "Valid expression bro";
    }
    else
    {
        cout << "Invalid expression bro";
    }
    return 0;
}