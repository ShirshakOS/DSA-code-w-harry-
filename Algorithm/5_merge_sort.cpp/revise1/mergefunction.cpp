// merge two sorted arrays into one array

#include <iostream>
using namespace std;

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int *a, int m, int *b, int n, int *c)
{
    int i = 0, j = 0, k = 0;
    // i tracks the index in array a
    // j tracks the index in array b
    // k tracks the index in array c
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

int main()
{
    int a[] = {1, 3, 5}, m = 3;
    int b[] = {2, 4, 6, 8, 10}, n = 5;
    int c[100];
    int x = m + n;
    merge(a, m, b, n, c);

    display(x, c);
}