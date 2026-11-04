#include <iostream>
using namespace std;

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void selectionsort(int n, int *a)
{
    int i, j, key, track;
    for (i = 0; i < n - 1; i++)
    {
        key = a[i];
        track = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < key)
            {
                key = a[j];
                track = j;
            }
        }
        a[track] = a[i];
        a[i] = key;
    }
}

int main()
{
    int a[] = {8, 0, 7, 99, 1, 3, 33};
    int n = 7;

    selectionsort(n, a);
    display(n, a);
    return 0;
}