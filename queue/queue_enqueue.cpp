#include <iostream>
using namespace std;

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

void traverse_queue(queue *p)
{
    int i = 0;
    while (i != p->r + 1)
    {
        cout << "Element: " << p->arr[i] << endl;
        i++;
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
    struct queue *p;
    p = new queue;
    p->size = 10;
    p->f = p->r = -1;
    p->arr = new int[p->size];
    // queue created

    p = enqueue(2, p);
    p = enqueue(3, p);
    p = enqueue(4, p);

    cout << "traversing:\n";
    traverse_queue(p);

    return 0;
}