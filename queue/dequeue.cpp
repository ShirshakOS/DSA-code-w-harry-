#include <iostream>
using namespace std;

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(queue *p)
{
    if (p->r == p->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traverse_queue(queue *p)
{
    int i = p->f + 1;

    while (i != p->r + 1)
    {
        cout << "Element: " << p->arr[i] << endl;
        i++;
    }
}

int dequeue(queue *p)
{
    if (isEmpty(p))
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    else
    {
        p->f++;
        int i = p->arr[p->f];
        return i;
    }
}

int isFull(queue *p)
{
    if (p->r == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

queue *enqueue(int data, queue *p)
{
    if (isFull(p))
    {
        cout << "Queue Overflow\n";
        return p;
    }
    else
    {
        p->r++;
        p->arr[p->r] = data;
        return p;
    }
}

int main()
{
    queue *p;
    p = new queue;
    p->size = 10;
    p->f = p->r = -1;
    p->arr = new int[p->size];
    // Successfully created a queue

    p = enqueue(4, p);
    p = enqueue(99, p);
    p = enqueue(88, p);

    cout << "Dequeuing element " << dequeue(p) << endl;
    cout << "Dequeuing element " << dequeue(p) << endl;
    cout << "Dequeuing element " << dequeue(p) << endl;
    cout << "Dequeuing element " << dequeue(p) << endl;

    return 0;
}