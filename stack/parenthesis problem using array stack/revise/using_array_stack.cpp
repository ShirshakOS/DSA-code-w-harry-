#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    int *arr;
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

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack underflow\n";
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
void push(char data, stack *ptr)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow! " << data << " can not be pushed\n";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int parenthesisCheck(char *exp)
{
    stack *sp;
    sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new int[sp->size];
    // stack created

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push('(', sp);
        }
else if (exp[i] == ')')
{
    if (isEmpty(sp))
    {
        delete[] sp->arr;
        delete sp;
        return 0;
    }
    pop(sp);
}
    }
    if (isEmpty(sp))
    {
        delete[] sp->arr;
        delete sp;
        return 1;
    }
    else
    {
        delete[] sp->arr;
        delete sp;
        return 0;
    }
}

int main()
{
    char exp[] = "8*3+(9+8))";
    if (parenthesisCheck(exp))
    {
        cout << "Valid expression\n";
    }
    else
    {
        cout << "Invalid expression\n";
    }
    return 0;
}