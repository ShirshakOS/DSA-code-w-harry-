#include <iostream>
#include <string.h>
// application of stack: infix to postfix
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
    if (sp->top == sp->size + 1)
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
        cout << "Stack Underflow!\n";
        return -1;
    }
    else
    {
        char x = sp->arr[sp->top];
        sp->top--;
        return x;
    }
}

void push(stack *sp, char x)
{
    if (isFull(sp))
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = x;
    }
}

int operands(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *Infix2Postfix(char *infix)
{
    stack *sp;
    sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    // stack is created

    int i = 0; // track infix traversal
    int j = 0; // track postfix addition
    char *postfix;
    postfix = new char[strlen(infix) + 1];
    while (infix[i] != '\0')
    {
        if (!operands(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(sp->arr[sp->top]))
            {
                push(sp, infix[i]);
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
    char infix[] = "a+b-c*d";
    cout << Infix2Postfix(infix) << endl;
    return 0;
}