#include <iostream>
using namespace std;

struct stack
{
    int top;
    int *arr;
    int size;
};

void push(stack *ptr, int value)
{
    if (ptr->top == ptr->size - 1)
    {
        cout << "Stack overflow! :( Im sorry bro You can't add " << value << "! Max capacity is reached.\n\n";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int stackTop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        cout << "~~Stack UnderFlow!! Im sorry bro :(. There's no element in the Stack\n\n";
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

int stackBottom(stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    // create stack
    struct stack *s;
    s = new stack;
    s->top = -1;
    s->size = 3;
    s->arr = new int[s->size];

    cout << "~~~~Stack is created!!!~~~~\n\n";

    push(s, 99);
    push(s, 88);
    push(s, 77);
    push(s, 66);

    cout << stackBottom(s) << " is at the BOTTOM POSITION of the stack -_- LUUUL XDD ~~~\n\n";

    cout << stackTop(s) << " is the element at the TOP POSITION of the stack O_O wowww!~~\n\n";

    return 0;
}