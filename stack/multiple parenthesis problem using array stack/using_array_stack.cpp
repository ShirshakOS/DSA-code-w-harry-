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
        cout << "Stack Overflow\n";
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = x;
    }
}

char pop(stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack UnderFLow!\n";
        return -1;
    }
    else
    {
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisCheck(char *exp)
{
    stack *sp;
    sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    // stack created

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i], sp);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                char poped = pop(sp);
                if (!match(poped, exp[i]))
                {
                    return 0;
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
    char exp[] = "(3+3)-33+(33+11)}";
    if (parenthesisCheck(exp))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }
    return 0;
}