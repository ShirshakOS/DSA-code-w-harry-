// double ended queue
#include <iostream>
using namespace std;

struct queue
{
    int f, r, size, *arr;
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

void enqueueFront(int data, queue **p)
{
    if (isFull(*p))
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        for (int i = (*p)->r; i >= 0; i--)
        {
            (*p)->arr[i + 1] = (*p)->arr[i];
        }
        (*p)->arr[0] = data;
        (*p)->r++;
    }
}

int main()
{
    queue *p;
    p = new queue;
    p->f = p->r = -1;
    p->size = 5;
    p->arr = new int[p->size];
    // Queue created

    enqueue(44, &p);
    enqueue(4, &p);
    enqueue(54, &p);
    enqueue(7, &p);

    cout << "Traversing Before Front Enqueue:\n";
    traverse_queue(p);

    enqueueFront(89, &p);

    cout << "Traversing After Front Enqueue:\n";
    traverse_queue(p);

    return 0;
}