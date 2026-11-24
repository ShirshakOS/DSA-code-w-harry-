// breadth first search graph traversal algorithm 

#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(queue *q)
{
    return q->r == q->f;
}

int isFull(queue *q)
{
    return q->r == q->size - 1;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
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
        q->f++;
        return q->arr[q->f];
    }
}

int main()
{
    queue *q = new queue;

    q->size = 400;
    q->f = q->r = 0;
    q->arr = new int[q->size];

    // BFS implementation

    int i = 0;

    int visited[7] = {0};

    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    cout << i << " ";
    visited[i] = 1;

    enqueue(q, i);

    while (!isEmpty(q))
    {
        int node = dequeue(q);

        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";

                visited[j] = 1;

                enqueue(q, j);
            }
        }
    }

    delete[] q->arr;
    delete q;

    return 0;
}
