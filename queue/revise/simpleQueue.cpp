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

void enqueue(int data, queue *p)
{
    if (isFull(p))
    {
        cout << "Queue OverFlow\n";
    }
    else
    {
        p->r++;
        p->arr[p->r] = data;
    }
}

void traverse(queue *p)
{
    int i = p->f + 1;
    while (i != p->r+1)
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
        int x;
        p->f++;
        x = p->arr[p->f];
        return x;
    }
}

int main()
{
    queue *p;
    p = new queue;
    p->size = 10;
    p->f = p->r = -1;
    p->arr = new int[p->size];
    // queue is created

    enqueue(33, p);
    enqueue(44, p);
    enqueue(89, p);

    cout << "Traversing: " << endl;
    traverse(p);

    return 0;
}