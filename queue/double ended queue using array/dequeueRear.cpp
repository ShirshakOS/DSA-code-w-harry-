// double ended queue
#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f, r, *arr;
};

int isEmpty(queue *p)
{
    if (p->f == p->r)
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
    if (p->r == p->size - 1)
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
    int i = 0;
    while (i != p->r + 1)
    {
        cout << "Element: " << p->arr[i] << endl;
        i++;
    }
}

void enqueue(int data, queue **p)
{
    if (isFull(*p))
    {
        cout << "Queue OverFlow\n";
    }
    else
    {
        (*p)->r++;
        (*p)->arr[(*p)->r] = data;
    }
}

int dequeueRear(queue *p)
{
    if (isEmpty(p))
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    else
    {
        int i = p->arr[p->r];
        p->r--;
        return i;
    }
}

int main()
{
    queue *q;
    q = new queue;
    q->size = 4;
    q->f = q->r = -1;
    q->arr = new int[q->size];
    // queue created

    enqueue(44, &q);
    enqueue(89, &q);
    enqueue(90, &q);

    cout << "Traversing before rear dequeue:\n";
    traverse_queue(q);

    cout << "\nDequeued: " << dequeueRear(q) << endl;
    cout << "Dequeued: " << dequeueRear(q) << endl;
    cout << "Dequeued: " << dequeueRear(q) << endl;
    return 0;
}