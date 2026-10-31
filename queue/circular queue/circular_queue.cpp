#include <iostream>
using namespace std;

struct queue
{
    int size, r, f, *arr;
};

int isEmpty(queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(queue *p)
{
    if (((p->r + 1) % p->size) == p->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *p, int data)
{
    if (isFull(p))
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        p->r = (p->r + 1) % p->size;
        p->arr[p->r] = data;
        cout<<"Enqueued element: "<<data<<endl;
    }
}

int dequeue(queue *p)
{
    if (isEmpty(p))
    {
        cout << "Queue UnderFlow\n";
        return -1;
    }
    else
    {
        p->f = (p->f + 1) % p->size;
        int a = p->arr[p->f];
        return a;
    }
}

int main()
{
    queue *p;
    p = new queue;
    p->size = 5;
    p->r = p->f = 0;
    p->arr = new int[p->size];
    // queue created

    enqueue(p, 88);
    enqueue(p, 90);
    enqueue(p, 11);

    cout << "Dequeued: " << dequeue(p) << endl;
    cout << "Dequeued: " << dequeue(p) << endl;

    enqueue(p, 22);
    enqueue(p, 87);
    enqueue(p, 99);
    cout << "Dequeued: " << dequeue(p) << endl;
    enqueue(p, 9);
    enqueue(p, 88);

    return 0;
}