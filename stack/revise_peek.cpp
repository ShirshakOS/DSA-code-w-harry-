// peek operation

#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
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

void push(stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack overflow! Cannot push " << value << " to the stack\n";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

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

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack underflow\n";
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int position)
{
    int arrayindex = ptr->top - position + 1; // general formula for the index when position of stack element is given
    if (arrayindex < 0)
    {
        cout << "Invalid position for the stack\n";
        return -1;
    }
    else
    {

        return ptr->arr[arrayindex];
    }
}
int main()
{
    struct stack *s;
    s = new struct stack;

    s->size = 4;
    s->top = -1;
    s->arr = new int[s->size];

    push(s, 1);
    push(s, 3);
    push(s, 2);
    push(s, 99);
    push(s, 88);

    cout << endl
         << "Popped " << pop(s) << " from the stack\n";

    cout << "\ntop " << s->top << endl
         << endl;

    for (int i = 1; i <= s->top + 1; i++)
    {
        cout << "Value at position " << i << " is " << peek(s, i) << endl;
    }

    if (isFull(s))
    {
        cout << "Stack full...\n";
    }
    else
    {
        cout << "Stack is not full yet!\n";
    }

    cout << "\nNow push 88 to the stack\n";
    push(s, 88);

    cout << endl
         << "Peeking the stack from position 1 to " << s->top << ": " << endl;
    for (int i = 1; i <= s->top + 1; i++)
    {
        cout << "Value at position " << i << " is " << peek(s, i) << endl;
    }
    return 0;
}