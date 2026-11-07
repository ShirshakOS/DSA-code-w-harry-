// merge sort
#include <iostream>
using namespace std;

void mergesort(int a[], int n1, int b[], int n2, int c[])
{
    int i = 0; // tracks a
    int j = 0; // tracks b
    int k = 0; // tracks c
    while (i < n1 && j < n2)
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
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        c[k] = b[j];
        k++;
        j++;
    }
}

void display(int n1, int n2, int *c)
{
    int n = n1 + n2;
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {2, 4, 6, 8};
    int n1 = 4;
    int b[] = {1, 3, 5, 7, 9, 11};
    int n2 = 6;
    int c[100];
    mergesort(a, n1, b, n2, c);
    display(n1, n2, c);
    return 0;
}