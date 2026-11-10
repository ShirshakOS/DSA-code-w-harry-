#include <iostream>
using namespace std;

void merge(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int x = 0; x < k; x++)
    {
        a[low + x] = b[x];
    }
}

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void display(int n, int *a)
{
    for (int x = 0; x < n; x++)
    {
        cout << a[x] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {32, 34, 45, 5, 623, 23};
    int n = 6;
    display(n, a);
    cout << endl;
    mergesort(a, 0, n - 1);
    display(n, a);
    return 0;
}