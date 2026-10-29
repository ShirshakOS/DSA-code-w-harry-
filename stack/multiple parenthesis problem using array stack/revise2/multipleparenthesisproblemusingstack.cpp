// include iostream header file
#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char x, stack *sp)
{
    if (isFull(sp))
    {
        cout << "Stack Overflow :(. " << sp->arr[sp->top] << " can not be pushed into the stack\n";
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = x;
    }
}

int check_match(char x, char y)
{
    if (x == '(' && y == ')')
    {
        return 1;
    }
    if (x == '{' && y == '}')
    {
        return 1;
    }
    if (x == '[' && y == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop(stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack underflow :(.\n ";
        return -1;
    }
    else
    {
        char x = sp->arr[sp->top];
        sp->top--;
        return x;
    }
}

int parenthesischeck(char *exp)
{
    stack *sp;
    sp = new stack;
    sp->top = -1;
    sp->size = 100;
    sp->arr = new char[sp->size];
    // stack is created

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i], sp);
        }
        else
        {
            if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (isEmpty(sp))
                {
                    return 0;
                }
                else
                {
                    if (!check_match(pop(sp), exp[i]))
                    {
                        return 0;
                        ;
                    }
                }
            }
        }
    }
    if (isEmpty(sp))
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
    char exp[] = "(9+1)-{99+22*(33-22)}";
    if (parenthesischeck(exp))
    {
        cout << "The expression is valid\n";
    }
    else
    {
        cout << "The expression is invalid\n";
    }
    return 0;
}