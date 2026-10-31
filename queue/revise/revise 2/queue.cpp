#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f, b;
    int *arr;
};

int isEmpty(queue *p)
{
    if (p->f == p->b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    else
    {
        int a;
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

void enqueue(int data, queue *p)
{
    if (p->b == p->size - 1)
    {
        cout << "Queue Overload\n";
    }
    else
    {
        p->b++;
        p->arr[p->b] = data;
    }
}

int main()
{
    queue *p;
    p = new queue;
    p->size = 10;
    p->f = p->b = -1;
    p->arr = new int[p->size];
    // created queue;

    enqueue(33, p);
    enqueue(32, p);
    enqueue(31, p);

    cout << "Dequeued: " << dequeue(p) << endl;
    cout << "Dequeued: " << dequeue(p) << endl;
    cout << "Dequeued: " << dequeue(p) << endl;
    cout << "Dequeued: " << dequeue(p) << endl;

    return 0;
}