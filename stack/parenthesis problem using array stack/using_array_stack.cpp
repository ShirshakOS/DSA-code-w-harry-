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

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        (ptr)->top--;
        return value;
    }
}

int parenthesisMatch(char *exp)
{
    struct stack *ptr;
    ptr = new stack;
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = new char[ptr->size];
    // stack created

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
            pop(ptr);
        }
    }
    if (isEmpty(ptr))
    {
        delete[] ptr->arr;
        delete ptr;
        return 1;
    }
    else
    {
        delete[] ptr->arr;
        delete ptr;
        return 0;
    }
}

int main()
{

    char exp[] = "(3-2)+22";

    //check if the stack is empty 
    if (parenthesisMatch(exp))
    {
        cout << "Valid expression bro";
    }
    else
    {
        cout << "Invalid expression bro";
    }
    return 0;
}