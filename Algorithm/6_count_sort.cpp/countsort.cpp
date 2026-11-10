#include <iostream>
#include <limits.h>
using namespace std;

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int maximum(int *a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countsort(int *a, int n)
{
    int max = maximum(a, n);
    int *b;
    b = new int[max];             // creating an array of size max
    for (int i = 0; i < max; i++) // initializing all the element of array b to zero
    {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= max; i++)
    {
        while (b[i] != 0)
        {
            a[k] = i;
            k++;
            b[i]--;
        }
    }
}

int main()
{
    int a[] = {9, 2, 5, 3, 0, 1, 1};
    countsort(a, 7);
    display(7, a);
    return 0;
}