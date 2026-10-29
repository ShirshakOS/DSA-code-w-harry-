#include <iostream>
using namespace std;
#include <string.h>
struct stack
{
    int top;
    char *arr;
    int size;
};

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ReturnPrecedence(char x)
{
    if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

char pop(stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack Underflow\n";
        return -1; //
    }
    else
    {
        char x = sp->arr[sp->top];
        sp->top--;
        return x;
    }
}

void push(char x, stack *sp)
{
    if (isFull(sp))
    {
        cout << "Stack Overflow(The stack is full)\n";
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = x;
    }
}

char *convert(char *infix)
{
    struct stack *sp;
    sp = new stack; // Allocate memory for stack in heap
    sp->top = -1;
    sp->size = 100;
    sp->arr = new char[sp->size]; // allocate memory for character array
    // stack is created

    char *postfix;
    postfix = new char[strlen(infix) + 1];

    int i = 0; // tracks the infix traversal
    int j = 0; // tracks the postfix traversal
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (ReturnPrecedence(infix[i]) > ReturnPrecedence(sp->arr[sp->top]))
            {
                push(infix[i], sp);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[] = "8-9*33/99+22";
    cout << "The postfix of " << infix << " is: " << convert(infix) << endl;
    return 0;
}