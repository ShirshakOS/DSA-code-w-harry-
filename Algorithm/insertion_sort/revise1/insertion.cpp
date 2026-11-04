#include <iostream>
using namespace std;

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void insertionsort(int n, int *a)
{
    int i, j, key, temp;
    for (i = 1; i < n; i++) // tracks the passes n-1 times
    {
        j = i - 1;
        key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {34, 12, 56, 77, 22};
    int n = 5;

    insertionsort(n, a);
    display(n, a);

    return 0;
}